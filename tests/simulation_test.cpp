#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/simulation.h"

using namespace testing;

TEST(SimulationTest, ValidFileTest){
  testing::internal::CaptureStdout();
  Simulation simulation("/home/beekebak/test_task/tests/test_files/valid_input1");
  simulation.StartSimulation();
  std::ifstream file("/home/beekebak/test_task/tests/test_files/valid_output1", std::ios_base::in);
  std::string expected(std::istreambuf_iterator<char>{file},
                               std::istreambuf_iterator<char>{});
  std::string got = ::internal::GetCapturedStdout();
  ASSERT_EQ(expected, got);
}
