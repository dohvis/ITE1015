#include <iostream>

#define NUM_OF_CHAT 200

class ReplyAdmin {
public:
    ReplyAdmin();

    ~ReplyAdmin();

    int getChatCount(); // : chats에 들어있는 chat의 갯수를 반환
    bool addChat(std::string _chat); // _chat을 chats에 추가 (추가 실패시 false 리턴)
    bool removeChat(int _index); // _index에 있는 chat 삭제 (_index가 없을시 false 리턴)
    bool removeChat(int _start, int _end); // _start부터 _end까지 chat을 모두 삭제 (하나라도 삭제 성공했을 시 true 리턴,
    // start가 음수거나 end가 chats보다 클 경우 해당되는 부분만 삭제)
    void printChats();
private:
    std::string *chats;
    int chatsCnt;
//    bool hasChat(int index);
};