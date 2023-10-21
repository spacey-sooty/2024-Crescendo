#include "utils/PID.h"

using namespace wom;

template<typename IN, typename OUT>
PIDConfig::PIDConfig(std::string path, kp_t kp = kp_t{0}, ki_t ki = ki_t{0}, kd_t kd = kd_t{0}, error_t stableThresh = error_t{-1}, deriv_t stableDerivThresh = deriv_t{-1}, in_t izone = in_t{-1})
      : path(path), kp(kp), ki(ki), kd(kd), stableThresh(stableThresh), stableDerivThresh(stableDerivThresh), izone(izone) {
      RegisterNT();
}

template<typename IN, typename OUT>
void PIDConfig::RegisterNT() {
  auto table = nt::NetworkTableInstance::GetDefault().GetTable(path);
  _nt_bindings.emplace_back(std::make_shared<NTBoundUnit<typename kp_t::unit_type>>(table, "kP", kp));
  _nt_bindings.emplace_back(std::make_shared<NTBoundUnit<typename ki_t::unit_type>>(table, "kI", ki));
  _nt_bindings.emplace_back(std::make_shared<NTBoundUnit<typename kd_t::unit_type>>(table, "kD", kd));
  _nt_bindings.emplace_back(std::make_shared<NTBoundUnit<typename error_t::unit_type>>(table, "stableThresh", stableThresh));
  _nt_bindings.emplace_back(std::make_shared<NTBoundUnit<typename deriv_t::unit_type>>(table, "stableThreshVelocity", stableDerivThresh));
  _nt_bindings.emplace_back(std::make_shared<NTBoundUnit<IN>>(table, "izone", izone));
}

