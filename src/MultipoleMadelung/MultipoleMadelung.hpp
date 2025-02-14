//
// Created by F.Moitzi on 16.12.2021.
//

#ifndef LSMS_MULTIPOLEMADELUNG_HPP
#define LSMS_MULTIPOLEMADELUNG_HPP

#include <complex>
#include <vector>

#include "Misc/Coeficients.hpp"
#include "Main/SystemParameters.hpp"
#include "common.hpp"

namespace lsms {

class MultipoleMadelung {
 private:
  /// Global number of atoms
  int num_atoms;

  /// Local number of atoms
  int local_num_atoms;

  double scaling_factor;
  double rscut;
  double kncut;

  std::vector<int> r_nm;
  int nrslat;

  std::vector<int> k_nm;
  int nknlat;

 public:
  /// Angular-momentum index cutoff l
  int lmax;

  /// Object for calculating the Madelung constants
  MultipoleMadelung(LSMSSystemParameters &lsms, CrystalParameters &crystal,
                    LocalTypeInfo &local, int lmax = 0);

  double getScalingFactor() const;

  double getRsCut() const;

  double getKnCut() const;

  std::vector<int> getRsSize() const;

  std::vector<int> getKnSize() const;
};

}  // namespace lsms

#endif
