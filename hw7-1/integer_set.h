#include <vector>

using namespace std;

class IntegerSet {
public:
    IntegerSet();

    ~IntegerSet();

    void AddNumber(int num);

    void DeleteNumber(int num);

    int GetItem(int pos) const;

    std::vector<int> GetAll() const;

private:
    std::vector<int> numbers_;
};
