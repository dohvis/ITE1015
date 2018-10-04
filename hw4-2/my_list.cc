#include <iostream>
#include <fstream>

using namespace std;


typedef struct studentInfo {
    string name;
    int age;
    string id;
    string subjects[10];
} StudentInfo;


namespace util {
    string* split(const string& str, const string& delim) {
        string* string_list = new string[10];

        int idx = 0;
        char * token = strtok(const_cast<char*>(str.c_str()), delim.c_str());
        while (token != NULL) {
            string_list[idx] = token;
            token = strtok(NULL, delim.c_str());
            ++idx;
        }

        return string_list;
    }

    int getSizeOfStringList(const string *array) {
        int i = 0;
        while (!array[i].empty()) ++i;
        return i;
    }

    void print(StudentInfo studentInfo) {
        printf("%s(%s): ", studentInfo.name.c_str(), studentInfo.id.c_str());
        
        int i=0;
        while(studentInfo.subjects[i].length() != 0) {
            if(i != 0) {
                cout << " & ";
            }
            cout << studentInfo.subjects[i];
            i++;
        }
        cout << endl;
    }
    bool startWith(string str, string pattern) {
        for(int i=0; i < pattern.length(); i++) {
            if (str[i] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
}

typedef struct _node {
	StudentInfo studentInfo;
    struct _node* next;
} Node;

class LinkedList {
    public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    int append(StudentInfo studentInfo);
    void printAllNodes();
    void printOnlyIDStartWith(string startWith);
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    Node* head = this->head;
    Node* tmp = head->next;
    while(tmp != NULL) {
        head->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
        tmp = head->next;
    }
    // cout << "LIST DELETED" << endl;
}


int LinkedList::append(StudentInfo studentInfo) {
    Node* node = new Node();
    node->studentInfo = studentInfo;
    node->next = this->head;
    this->head = node;
    this->length++;
    return this->length;
}

void LinkedList::printAllNodes() {
    Node* head = this->head;
    while(head != NULL) {
        util::print(head->studentInfo);
        head = head->next;
    }
}

void LinkedList::printOnlyIDStartWith(string startWith) {
    Node* head = this->head;
    while(head != NULL) {
        if(util::startWith(head->studentInfo.id, startWith)) {
            util::print(head->studentInfo);
        }
        head = head->next;
    }
}

StudentInfo createStudentInfo(string name, int age, string id, string subjects[]) {
    StudentInfo studentInfo;
    studentInfo.name = name;
    studentInfo.age = age;
    studentInfo.id = id;
    int i = 0;
    while(!subjects[i].empty()) {
        studentInfo.subjects[i] = subjects[i];
        // cout << "[*] create student info: " << studentInfo.subjects[i] << endl;
        i++;
    } 
    return studentInfo;
}

int main() {
    string line;
    string *splitedData;
    string name, id;
    int age;
    LinkedList* list = new LinkedList();
    string *inputSubjects;

    ifstream fp ("input.txt");
    if (fp.is_open()) {
        while (getline(fp, line)) {
            splitedData = util::split(line, ":");
            
            name = splitedData[0];
            age = stoi(splitedData[1]);
            id = splitedData[2];
            
            inputSubjects = util::split(splitedData[3], ",");
            string subjects[10];
            
            int i=0;
            while(inputSubjects[i].length() != 0) {
                subjects[i] = inputSubjects[i];
                i++;
            }
            
            StudentInfo studentInfo = createStudentInfo(name, age, id, subjects);
            list->append(studentInfo);
        }
    }
    fp.close();
    list->printOnlyIDStartWith("2013");
    delete list;
    return 0;
}
