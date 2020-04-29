// apple.cpp 
class Apple
{
private:
    int people[100];
public:
    Apple(int i);
    const int apple_number;
    void take(int num) const; // 常函数
    int add(int num);
    int add(int num) const;
    int getCount() const;

};
