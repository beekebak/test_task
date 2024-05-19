 #include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/simulation.h"

using namespace testing;

class SimulationTest: public
               testing::TestWithParam<std::pair<std::string, std::string>>{

};

TEST_P(SimulationTest, ValidFileTest){
  testing::internal::CaptureStdout();
  Simulation simulation("tests/test_files/" + GetParam().first);
  simulation.StartSimulation();
  std::ifstream file("tests/test_files/" + GetParam().second, std::ios_base::in);
  std::string expected(std::istreambuf_iterator<char>{file},
                               std::istreambuf_iterator<char>{});
  std::string got = ::internal::GetCapturedStdout();
  ASSERT_EQ(expected, got);
}

INSTANTIATE_TEST_SUITE_P(MyGroup, SimulationTest, testing::Values(
                        std::pair<std::string, std::string>{"valid_input1",
                                                            "valid_output1"},
                        std::pair<std::string, std::string>{"valid_input2",
                                                            "valid_output2"},
                        std::pair<std::string, std::string>{"valid_input3",
                                                            "valid_output3"},
                        std::pair<std::string, std::string>{"valid_input4",
                                                            "valid_output4"},
                        std::pair<std::string, std::string>{"invalid_input",
                                                            "invalid_output"}));
