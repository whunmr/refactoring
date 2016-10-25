#include <gtest/gtest.h>
#include "test_common.h"
using namespace std;
________________________________REFACTORING_TARGET_AS_BELLOW

struct Msg {
    int type;
};

#define S1AP_INIT_CTXT_SETUP 0x33

struct AuglyMsgHandler {
    bool foo(const Msg &msg) const {
        cout << msg.type << endl;
        return true;
    }

    bool bar(const Msg &msg) const {
        cout << msg.type << endl;
        return true;
    }
};

struct AuglyMsgHandler_XXX {
    bool foo(const Msg &msg) const {
        cout << msg.type << endl;
        return true;
    }

    int xxx(const Msg& msg) const {
        return msg.type;
    }
};

/*-----------------------------------------------------------*/

struct MsgHandler {
    bool foo(const Msg &msg) const {
        //????????????
        return false;
    }
};

________________________________REFACTORING_BE_TESTED_BY(duplicated_code_test)


TYPED_TEST(duplicated_code_test, should_able_to_return_true__on_s1_msg) {
    Msg msg = {S1AP_INIT_CTXT_SETUP};

    ASSERT_TRUE(this->foo(msg));
}
