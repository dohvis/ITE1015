enum EFighterStatus {
    Invalid = 0,
    Alive,
    Dead,
};
typedef enum EFighterStatus FighterStatus;

class MinimalFighter {
public:
    MinimalFighter();// : 체력 0, 공격력 0, 상태 ‘Invalid’로 초기화
    MinimalFighter(int _hp, int _power);// : 체력과 공격력을 주어진 값으로, 상태 ‘Alive’나 ‘Dead’로
    int mHp; // (체력)
    int mPower; // (공격력)
    FighterStatus mStatus; // (상태: Invalid, Alive, Dead - defined by enum)
private:
    int hp();// const
    int power();//const
    FighterStatus status();// const : 체력, 공격력, 상태를 리턴
    void setHp(int _hp);// : 체력을 변경
    void hit(MinimalFighter *_enemy);// : Hit 명령 수행
    void attack(MinimalFighter *_target);// : Attack 명령 수행
    void fight(MinimalFighter *_enemy);// : Fight 명령 수행
};
