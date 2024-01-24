#include <iostream>
// 1. ������� ����� ��������� ��������
// 2. ������� ����� � �����
// 3. ��������� ������� �������� �����
// 4. ��������� �������� �� ���� �������� �����
// 5. ����������� ������ ������ �� ����: 
// 5.1 - ���� ����� ��������� ��� ������
// 5.2 - � ������ ���� �������� �������� - ������� ����� � 
// ������ ���������� ������ � �����
// 5.3 - � ������ ���� �������� ���������� - �������� ������������ �� ���� 
// � ������� ��������� ����������� ������

class  Cassa {                  // 1
public:
	Cassa():money_(0){}
	// ��� money_ = 0;

	int CurrentMoney() {        // 2
		return money_;
	}

	void CashIn(int money) {    // 3
		this->money_ += money;
	}

	void CashOut(int money) {   // 4
		if (money > money_) {
			std::cerr << "not enough money | �� ���������� ����� ";
			return;
		}
		this->money_ -= money;
	}

	int Exchenge(int ticket, int money) { // 5
		if (money < ticket) {             // 5.3
			std::cerr << "not enough money for operation | �� ���������� ����� ��� ��������\n";
			return money;
		}
		if (money_ < money - ticket) {    // 5.3
			std::cerr << "not enough money for return change | �� ���������� ����� ��� �����\n";
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

	std::cout << "first cassa has | � ������ ����� ���� " << var1.CurrentMoney() << " money\n\n";
	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n\n";

	var1.CashOut(2000);
	std::cout << "first cassa has | � ������ ����� ����  " << var1.CurrentMoney() << " money\n";
	var1.CashOut(200);
	std::cout << "first cassa has | � ������ ����� ����  " << var1.CurrentMoney() << " money\n\n";


	var2.CashOut(10);
	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	var2.CashOut(0);
	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n\n";

	int change = 0;
	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	change = var2.Exchenge(100, 20);
	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	std::cout << "change is - | ����� - " << change << '\n';

	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	change = var2.Exchenge(100, 120);
	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	std::cout << "change is - | ����� - " << change << '\n';

	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	change = var2.Exchenge(100, 100);
	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	std::cout << "change is - | ����� - " << change << '\n';

	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	change = var2.Exchenge(10, 20);
	std::cout << "second cassa has | �� ������ ����� ���� " << var2.CurrentMoney() << " money\n";
	std::cout << "change is - | ����� - " << change << '\n';




	return 0;
}