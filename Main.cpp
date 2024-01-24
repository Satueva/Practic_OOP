#include <iostream>
// 1. Создать класс кассового аппарата
// 2. Сколько денег в кассе
// 3. Позволять вносить денежную сумму
// 4. Позволяет забирать из него денежную сумму
// 5. Производить расчет оплаты по чеку: 
// 5.1 - приём суммы требуемой для оплаты
// 5.2 - в случае если операция возможна - вернуть сдачу и 
// внести полученные деньги в кассу
// 5.3 - в случае если операция невозможна - сообщить пользователю об этом 
// и вернуть преданные покупателем деньги

class  Cassa {                  // 1
public:
	Cassa():money_(0){}
	// или money_ = 0;

	int CurrentMoney() {        // 2
		return money_;
	}

	void CashIn(int money) {    // 3
		this->money_ += money;
	}

	void CashOut(int money) {   // 4
		if (money > money_) {
			std::cerr << "not enough money | не достаточно денег ";
			return;
		}
		this->money_ -= money;
	}

	int Exchenge(int ticket, int money) { // 5
		if (money < ticket) {             // 5.3
			std::cerr << "not enough money for operation | не достаточно денег для операции\n";
			return money;
		}
		if (money_ < money - ticket) {    // 5.3
			std::cerr << "not enough money for return change | не достаточно денег для сдачи\n";
			return money;
		}
		money_ += ticket;                 // 5.2
		return money - ticket;
	}

private:
	int money_;
};

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	Cassa var1;
	Cassa var2;

	var1.CashIn(1000);

	std::cout << "first cassa has | в первой кассе есть " << var1.CurrentMoney() << " money\n\n";
	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n\n";

	var1.CashOut(2000);
	std::cout << "first cassa has | в первой кассе есть  " << var1.CurrentMoney() << " money\n";
	var1.CashOut(200);
	std::cout << "first cassa has | в первой кассе есть  " << var1.CurrentMoney() << " money\n\n";


	var2.CashOut(10);
	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	var2.CashOut(0);
	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n\n";

	int change = 0;
	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	change = var2.Exchenge(100, 20);
	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	std::cout << "change is - | сдача - " << change << '\n';

	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	change = var2.Exchenge(100, 120);
	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	std::cout << "change is - | сдача - " << change << '\n';

	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	change = var2.Exchenge(100, 100);
	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	std::cout << "change is - | сдача - " << change << '\n';

	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	change = var2.Exchenge(10, 20);
	std::cout << "second cassa has | во второй кассе есть " << var2.CurrentMoney() << " money\n";
	std::cout << "change is - | сдача - " << change << '\n';




	return 0;
}