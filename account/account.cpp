#include <iostream>
#include <string>
#include <random>

using std::string;

class BankAccount
{
  private:
      // TODO: declare member variables
    int number;
    string holder;
    float amount;

  public:
      // TODO: declare setters
    BankAccount(string holder, float amount): holder(holder), amount(amount) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist7(1000000,9999999); 
        this->number = dist7(rng);
    };
    void Holder(string holder);
    void Amount(float amount);
    
      // TODO: declare getters
    string Holder();
    float Amount();
    int Number();
};

// TODO: implement getters
string BankAccount::Holder() {
    return this->holder;
}
float BankAccount::Amount() {
    return this->amount;
}
int BankAccount::Number() {
    return this->number;
}

// TODO: implement setters
void BankAccount::Holder(string holder) {
    this->holder = holder;
}
void BankAccount::Amount(float amount) {
    this->amount = amount;
}


int main(){
    // TODO: instantiate and output a bank account
    BankAccount b = BankAccount("Mr. X", 100.00);
    
    std::cout << b.Number() << " " << b.Holder() << ": " << b.Amount() << std::endl;
    
    b.Amount(120.00);
    
    std::cout << b.Holder() << ": " << b.Amount() << std::endl;
    
}