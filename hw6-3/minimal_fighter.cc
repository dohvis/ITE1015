#include "minimal_fighter.h"


MinimalFighter::MinimalFighter() {
    // : 체력 0, 공격력 0, 상태 ‘Invalid’로 초기화
    this->mHp = 0;
    this->mPower = 0;
    this->mStatus = Invalid;
}

MinimalFighter::MinimalFighter(int _hp, int _power) {
    // : 체력과 공격력을 주어진 값으로, 상태 ‘Alive’나 ‘Dead’로
    this->setHp(_hp);
    this->mPower = _power;
    this->mStatus = Alive;
}


const int MinimalFighter::hp() const {
    return this->mHp;
}

const int MinimalFighter::power() const {
    return this->mPower;
}

FighterStatus MinimalFighter::status() const {
    // const : 체력, 공격력, 상태를 리턴
    return this->mStatus;
}

void MinimalFighter::setHp(int _hp) {
    this->mHp = _hp;
    if (this->mHp <= 0) {
        this->mStatus = Dead;
    }
}

void MinimalFighter::hit(MinimalFighter *_enemy) {
    // Fighter가 enemy와 공격을 동시에 한 번씩 교환한다. 공격을 하면 공격력만큼 상대방의 체력이 감소된다.
    int hp = 0;
    hp = _enemy->hp() - this->power();
    _enemy->setHp(hp);

    hp = this->hp() - _enemy->power();
    this->setHp(hp);
}

void MinimalFighter::attack(MinimalFighter *_target) {
    // Fighter가 target을 일방적으로 공격한다.
    // target의 체력이 공격력만큼 감소하며, Fighter의 공격력이 0이 된다. Fighter의 체력은 변화가 없다.
    int hp = _target->hp() - this->power();
    _target->setHp(hp);

    this->mPower = 0;
}

void MinimalFighter::fight(MinimalFighter *_enemy) {
    // Fighter와 enemy가 둘 중 하나가 죽을 때까지 공격을 교환한다.
    // 동시에 죽을 경우 둘 다 죽은 것으로 처리한다.
    while (this->status() != Dead && _enemy->status() != Dead) {
        this->hit(_enemy);
    }
}
