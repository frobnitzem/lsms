//
// Created by F.Moitzi on 07.01.2022.
//

#ifndef LSMS_MADELUNG_TERM_HPP
#define LSMS_MADELUNG_TERM_HPP

#include <algorithm>
#include <complex>
#include <numeric>
#include <vector>

#include "associatedLegendreFunction.hpp"
#include "common.hpp"
#include "utils.hpp"

namespace lsms {

/**
 * Reciprocal space term of Madelung sum:
 *
 *                                       2   2       -> ->
 *                4*pi          1    -eta *Kq /4 - i*Kq*aij
 *       term1 =  ---- * sum  ----- e
 *                tau    q<>0    2
 *                             Kq
 *
 *       note sum starts at 2 since kn=0.0 of 1/(rs-aij) is
 *       canceled by kn=0.0 of the 1/rs sum.
 *
 */
template <class T>
inline T reciprocal_space_term(matrix<T> &knlat, std::vector<T> &knlatsq,
                               std::vector<T> &aij, int nknlat, double eta,
                               double omega) {
  auto term12 = 0.0;
  auto fac = eta * eta / 4.0;

  for (auto i = nknlat - 1; i > 0; i--) {
    term12 += std::exp(-fac * knlatsq[i]) / knlatsq[i] *
              std::cos(knlat(0, i) * aij[0] + knlat(1, i) * aij[1] +
                       knlat(2, i) * aij[2]);
  }
  term12 = 4.0 * M_PI / omega * term12;

  return term12;
}

/**
 * Real space term of Madelung sum:
 *
 *                              ->   ->
 *                     1 - erf(|Rn + aij|/eta)
 *        term2 = sum -------------------------
 *                 n         ->   ->
 *                         |Rn + aij|
 *
 *        note for calculation of aij=0.0 term ibegin=2.
 *
 */
template <class T>
inline T real_space_term(matrix<T> &rslat, std::vector<T> &aij, int nrslat,
                         int ibegin, T eta) {
  /*
   *  subtract aij from rslat and calculate rslatmd which is used in
   *  calculating the real-space integral
   *  rslatmd, and aij are in the units of a0 = 1
   */

  auto rterm = 0.0;

  double rslatmd;

  for (auto i = ibegin; i < nrslat; i++) {
    rslatmd = std::sqrt((rslat(0, i) - aij[0]) * (rslat(0, i) - aij[0]) +
                        (rslat(1, i) - aij[1]) * (rslat(1, i) - aij[1]) +
                        (rslat(2, i) - aij[2]) * (rslat(2, i) - aij[2]));

    rterm += std::erfc(rslatmd / eta) / rslatmd;
  }

  return rterm;
}

/**
 * Dl sum
 */
void dlsum(std::vector<Real> &aij, matrix<Real> &rslat, int nrslat, int ibegin,
           matrix<Real> &knlat, int nknlat, double omega, int lmax_mad,
           double eta, std::vector<Complex> &dlm);

}  // namespace lsms

#endif  // LSMS_MADELUNG_TERM_HPP
