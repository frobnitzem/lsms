/* -*- c-file-style: "bsd"; c-basic-offset: 2; indent-tabs-mode: nil -*- */
#ifndef LSMS_CORESOLVER_HPP
#define LSMS_CORESOLVER_HPP

#include "Main/SystemParameters.hpp"
#include "Communication/LSMSCommunication.hpp"

extern "C"
{
  void deepst_(int *nqn, int *lqn, int *kqn, Real *en, Real *rv, Real *r, Real *rf, Real *h, Real *z, Real *c,
               int *nitmax, Real *tol, int *nws, int *nlast, int *iter, int *iprpts, int *ipdeq);
  void semcst_(int *nqn, int *lqn, int *kqn, Real *en,Real *rv, Real *r, Real *rf, Real *h, Real *z, Real *c,
               int *nitmax, Real *tol, int *nmt, int *nws, int *nlast, int *iter, int *iprpts,int *ipdeq);
  void newint_(int *nr, Real *r, Real *f, Real *g, int *ip0);
}

void getCoreStates(LSMSSystemParameters &lsms, AtomData &atom);


#endif
