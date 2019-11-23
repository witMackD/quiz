#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

class Question {
    friend std::ostream &operator <<(std::ostream &s, const Question &q);
    friend bool equal(const Question &q1, const Question &q2);
public:
    static Question draw();
    Question();
    Question(int a, int b);
    int operator()() const;
private:
    int a, b; };

std::ostream &operator<<(std::ostream &s, const Question &q) {
   return s << q.a << " " << q.b << " ";
    }

bool equal(const Question &q1, const Question &q2) {
    return q1.a == q2.a && q1.b == q2.b ||
           q1.a == q2.b && q1.b == q2.a; }

bool operator <(const Question &q1, const Question &q2){
return q1() < q2();
}
Question Question::draw() {
    return Question(1 + std::rand() % 10, 1 + std::rand() % 10); }

Question::Question(): a(), b() {}

Question::Question(int a, int b): a(a), b(b) {}

int Question::operator()() const {
    return a * b; }

int main() {
    std::srand(std::time(nullptr));
    Question qs[10];
    for (int i1 = 0; i1 < 10; ++i1) {
        int i2;
        do {
            qs[i1] = Question::draw();
            for (i2 = 0; !equal(qs[i2], qs[i1]); ++i2); }
        while (i2 < i1); }

        std::sort(qs, qs + 10);

    for (int i = 0; i < 10; ++i) {
        int u;
        do {
            std::cout << qs[i];
            std::cin >> u; }
        while (u != qs[i]()); }}
