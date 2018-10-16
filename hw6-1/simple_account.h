class User {
public:
    User();
    User(int id);

    int balance;
    int id;

    bool deposit(int inputAmount);

    bool withDraw(int inputAmount);

    bool transfer(User *to, int inputAmount);

};
