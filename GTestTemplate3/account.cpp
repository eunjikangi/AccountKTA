class Account {
public:
	Account(int balance) : balance{ balance } {}

	int getBalace() {
		return balance;
	}

	void deposit(int money) {
		balance += money;
	}

	void withdraw(int money) {
		balance -= money;
	}

	int getBalanceApplyInterest(int bal, int rate) {
		return bal * rate * 0.01;
	}

	void updateInterest() {
		balance += getBalanceApplyInterest(balance, rate);
	}

	void setInterest(int rate) {
		this->rate = rate;
	}

	int getPredictInterest(int year) {
		int predictBalance = balance;

		for (int i = 0; i < year; i++) {
			predictBalance += getBalanceApplyInterest(predictBalance, rate);
		}

		return predictBalance;
	}
private:
	int balance;
	int rate = {5};
};