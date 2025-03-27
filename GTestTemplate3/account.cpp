class Account {
public:
	Account(int balance) : balance{ balance } {}

	int getBalace() {
		return balance;
	}

private:
	int balance;
};