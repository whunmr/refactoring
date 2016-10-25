#include <gtest/gtest.h>
#include "test_common.h"

________________________________REFACTORING_TARGET_AS_BELLOW

    struct Msg {
        int type;
    };

    #define S1AP_INIT_CTXT_SETUP 0x33

    struct ArgulyMsgHandler {
        bool is_s1_ctxt_setup_msg(const Msg &msg) const {
            if (msg.type == S1AP_INIT_CTXT_SETUP) {
                return true;
            } else {
                return false;
            }
        }
    };

    struct MsgHandler {
        bool is_s1_ctxt_setup_msg(const Msg &msg) const {
            //????????????
            return false;
        }
    };

________________________________REFACTORING_GUARD_BY(xx)


TYPED_TEST(xx, should_able_to_return_true__on_s1_msg) {
    Msg msg = {S1AP_INIT_CTXT_SETUP};

    ASSERT_TRUE(this->is_s1_ctxt_setup_msg(msg));
}

