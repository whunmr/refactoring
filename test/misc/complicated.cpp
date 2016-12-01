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
        int broadcastMsgFlag;
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

    #define DIGIT_1 1
    #define DIGIT_0 0
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
            cout << "msg: enter" << endl;
            if (buf == nullptr || len < sizeof(MsgA)) {
                cout << "invalid input message" << endl;
                return false;
            }

            MsgA* msg = (MsgA*)buf;

            //优先级为0 表示优先级未指定 且为广播消息 丢弃消息
            //优先级为1 表示最低优先级 且为广播消息 丢弃消息
            if (msg->broadcastMsgFlag == 1 && (msg->priority == DIGIT_1 || msg->priority == DIGIT_0)) {
                cout << "drop low priority broadcast msg begin" << endl;
                cout << msg->eventId << endl;
                cout << msg->priority << endl;
                cout << "drop low priority broadcast msg end" << endl;
                return false;
            }

            cout << "forwarding message to peer begin" << endl;
            cout << len << endl;
            cout << "forwarding message to peer end" << endl;

            cout << "msg: exit" << endl;
            return true;
        }

        bool onMsgB(void* buf, size_t len) const {
            cout << "msg: begin" << endl;
            if (buf == nullptr || len < sizeof(MsgB)) {
                cout << "invalid input message" << endl;
                return false;
            }

            cout << "forwarding message to peer begin" << endl;
            cout << len << endl;
            cout << "forwarding message to peer end" << endl;

            cout << "msg: end" << endl;
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

#if 0

TYPED_TEST(complicated_test, should_able_to_return_true__on_s1_msg) {
    MsgA msg = {EVENT_A};

    ASSERT_TRUE(this->onMsg(&msg, sizeof(msg)));
}

TYPED_TEST(complicated_test, should_able_to_return_false__on_msg_without_enough_payload) {
    MsgHeader msg = {EVENT_A};

    ASSERT_TRUE(this->onMsg(&msg, sizeof(msg)));
}

#endif