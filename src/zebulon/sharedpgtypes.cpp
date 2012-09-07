#include <mpc-walkgen/zebulon/sharedpgtypes.h>
#include "../common/tools.h"

using namespace MPCWalkgen::Zebulon;

MPCSolution::MPCSolution()
:state_vec(4)
{}

MPCData::MPCData()
:QPSamplingPeriod(0.16)
,MPCSamplingPeriod(0.02)
,actuationSamplingPeriod(0.02)
,nbSamplesQP(10)
{}

int MPCData::nbSamplesControl() const{
  return static_cast<int> (round(MPCSamplingPeriod / actuationSamplingPeriod) );
}

int MPCData::nbSamplesMPC() const{
  return static_cast<int> (round(QPSamplingPeriod / MPCSamplingPeriod) );
}


RobotData::RobotData()
  :CoMHeight(0.45)
  ,b(0.264*0.8)
  ,h(0.252*0.8)
  ,deltaComXLocal(0.015)
  ,baseLimit(3)
  ,orientationLimit(3)
{
  baseLimit[0]=0.83*10;
  baseLimit[1]=1*10;
  baseLimit[2]=50*10;
  orientationLimit[0]=2*3.14;
  orientationLimit[1]=3*3.14;
  orientationLimit[2]=6*3.14;
  comLimitX=0.071*0.8;
  comLimitY=0.044*0.8;
}

QPPonderation::QPPonderation(int nb)
  :baseInstantVelocity(nb)
  ,basePosition(nb)
  ,basePositionInt(nb)
  ,CopCentering(nb)
  ,CoMCentering(nb)
  ,CoMJerkMin(nb)
  ,baseJerkMin(nb)
  ,OrientationInstantVelocity(nb)
  ,OrientationPosition(nb)
  ,OrientationJerkMin(nb)
{

  // Normal moveTo
  CopCentering[0]        = 0;
  CoMCentering[0]        = 10;
  CoMJerkMin[0]          = 0.00001;
  baseJerkMin[0]         = 0;
  baseInstantVelocity[0] = 1;
  basePosition[0]        = 1;
  basePositionInt[0]     = 0;

  OrientationInstantVelocity[0] = 1;
  OrientationPosition[0]        = 1;
  OrientationJerkMin[0]         = 0;

  // More stable moveTo
  CopCentering[1]        = 130;
  CoMCentering[1]        = 0;
  CoMJerkMin[1]          = 0.01;
  baseJerkMin[1]         = 0;
  baseInstantVelocity[1] = 1;
  basePosition[1]        = 1;
  basePositionInt[1]     = 0;

  OrientationInstantVelocity[1] = 1;
  OrientationPosition[1]        = 1;
  OrientationJerkMin[1]         = 0;


  // Normal move
  CopCentering[2]        = 0;
  CoMCentering[2]        = 10;
  CoMJerkMin[2]          = 0.00001;
  baseJerkMin[2]         = 0;
  baseInstantVelocity[2] = 1;
  basePosition[2]        = 0;
  basePositionInt[2]     = 0;

  OrientationInstantVelocity[2] = 1;
  OrientationPosition[2]        = 0;
  OrientationJerkMin[2]         = 0;


  // More stable move
  CopCentering[3]        = 130;
  CoMCentering[3]        = 0;
  CoMJerkMin[3]          = 0.01;
  baseJerkMin[3]         = 0;
  baseInstantVelocity[3] = 1;
  basePosition[3]        = 0;
  basePositionInt[3]     = 0;

  OrientationInstantVelocity[3] = 1;
  OrientationPosition[3]        = 0;
  OrientationJerkMin[3]         = 0;

  activePonderation = 0;
}


