#include <gtest/gtest.h>
#include "test_common.h"
using namespace std;
________________________________REFACTORING_TARGET_AS_BELLOW

    struct MsgHeader {
        int eventId;
    };

    struct MsgA {
        int eventId;
        int index;
        int subIndex;
        int priority;
        int a;
        int b;
        bool isBroadcastMsg;
        char c;
    };

    struct MsgB {
        int eventId;
        int mmeId;
        int enbId;
        int d;
        int e;
    };

    #define EVENT_A 0x01
    #define EVENT_B 0x02

    void forwardMsgToPeer(void* buf, size_t len) {
        cout << "forwarding message" << endl;
    }

/*-----------------------------------------------------------*/
    struct Before {

        bool onMsg(void* buf, size_t len) const {
            if (buf != nullptr && len >= sizeof(MsgHeader)) {
                MsgHeader* header = (MsgHeader*)buf;
                switch (header->eventId) {
                    case EVENT_A:
                        return onMsgA(buf, len);

                    case EVENT_B:
                        return onMsgB(buf, len);

                    default:
                        return false;
                }
            }

            cout << "invalid message" << endl;
            return false;
        }

        bool onMsgA(void* buf, size_t len) const {
            cout << "onMsgA: enter" << endl;
            if (buf == nullptr || len < sizeof(MsgA)) {
                cout << "invalid input message" << endl;
                return false;
            }

            MsgA* msg = (MsgA*)buf;
            if (msg->isBroadcastMsg && (msg->priority < 5 && msg->priority != 0)) {
                cout << "drop low priority broadcast msg" << endl;
                return false;
            }

            forwardMsgToPeer(msg, sizeof(msg));

            cout << "onMsgB: exit" << endl;
            return true;
        }

        bool onMsgB(void* buf, size_t len) const {
            cout << "onMsgB: begin" << endl;
            if (buf == nullptr || len < sizeof(MsgB)) {
                cout << "invalid input message" << endl;
                return false;
            }

            cout << "onMsgB: end" << endl;
            return true;
        }
    };


/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
    struct After {
        bool onMsg(void* buf, size_t len) const {
            //????????????
            return false;
        }
    };



________________________________REFACTORING_BE_TESTED_BY(complicated_test)


TYPED_TEST(complicated_test, should_able_to_return_true__on_s1_msg) {
    MsgA msg = {EVENT_A};

    ASSERT_TRUE(this->onMsg(&msg, sizeof(msg)));
}

TYPED_TEST(complicated_test, should_able_to_return_false__on_msg_without_enough_payload) {
    MsgHeader msg = {EVENT_A};

    ASSERT_TRUE(this->onMsg(&msg, sizeof(msg)));
}
