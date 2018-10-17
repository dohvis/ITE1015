#include <iostream>
#include "reply_admin.h"

using namespace std;

ReplyAdmin::ReplyAdmin() {
    this->chats = new string[NUM_OF_CHAT];
    this->chatsCnt = 0;
}

ReplyAdmin::~ReplyAdmin() {
    delete this->chats;
}


int ReplyAdmin::getChatCount() {
    return this->chatsCnt;
}

bool ReplyAdmin::addChat(string chat) {
    if (this->chatsCnt >= 200) {
        return false;
    }
    this->chats[this->chatsCnt] = chat;
    this->chatsCnt += 1;
    return true;
    // _chat을 chats에 추가 (추가 실패시 false 리턴)
}

bool ReplyAdmin::removeChat(int index) {
    if (index > this->chatsCnt) {
        return false;
    }
    this->chatsCnt -= 1;
    this->chats[index] = "";
//    for (int i = index; i < this->chatsCnt; i++) {
//        this->chats[i] = this->chats[i + 1];
//    }
    return true;
}// _index에 있는 chat 삭제 (_index가 없을시 false 리턴)

bool ReplyAdmin::removeChat(int start, int end) {
    if (start < 0) {
        start = 0;
    }
    if (end > this->chatsCnt) {
        end = this->chatsCnt;
    }
    for (int i = start; i < end; i++) {
        this->removeChat(i);
    }
    return true;
}// _start부터 _end까지 chat을 모두 삭제 (하나라도 삭제 성공했을 시 true 리턴,// start가 음수거나 end가 chats보다 클 경우 해당되는 부분만 삭제)

void ReplyAdmin::printChats() {
    for (int i = 0; i < this->chatsCnt; i++) {
        cout << i << " " << this->chats[i] << endl;
    }
}