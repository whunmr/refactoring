#ifndef REFACTORING_TEST_COMMON_H_H
#define REFACTORING_TEST_COMMON_H_H

#define ________________________________REFACTORING_TARGET_AS_BELLOW  namespace {


#define ________________________________REFACTORING_GUARD_BY(TestFixtureName) \
}  /* namespace {*/                                                           \
                                                                              \
template <typename T>                                                         \
  class TestFixtureName : public T, public ::testing::Test {                  \
};                                                                            \
                                                                              \
typedef ::testing::Types<ArgulyMsgHandler, MsgHandler> TestTargets;           \
TYPED_TEST_CASE(TestFixtureName, TestTargets);


#endif //REFACTORING_TEST_COMMON_H_H
