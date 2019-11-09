#include <cstdlib>
#include <ctime>
#include <iostream>

class Question{
    friend void print(const Question &q);
    friend bool equal(const Question &q1, const Question &q2);
public:
    Question(int a, int b);
    Question();
    int solution() const;
    static Question draw();
private:
    int a,b;

};

int Question::solution() const{
return a*b;
}

Question::Question(int a, int b): a(a), b(b){}
Question::Question()a(),b(){};

void print(const Question &q){
    std::cout << q.a << " " << q.b << " ";
}

Question Question::draw(){
    return Question (1 + std::rand() % 10,1 + std::rand() % 10);
}


int main() {
    std::srand(std::time(nullptr));
    Question questions[10];

    for (int i = 0; i < 10; ++i) {
        int answer;
        do {
            print(questions[i]);
            std::cin >> answer; }
        while (answer != questions[i].solution()); }}
