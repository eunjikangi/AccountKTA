#include "gmock/gmock.h"
#include "account.cpp"

using namespace std;

class AccountFixture : public testing::Test {
public:
	Account account{ 10000 };
};


TEST_F(AccountFixture, CreateAccountInit10000won)
{
	EXPECT_EQ(10000, account.getBalace());
}

TEST_F(AccountFixture, Deposit)
{
	account.deposit(500);
	EXPECT_EQ(10500, account.getBalace());
}

TEST_F(AccountFixture, Withdraw)
{
	account.withdraw(600);
	EXPECT_EQ(9400, account.getBalace());
}

TEST_F(AccountFixture, FivePercentInterest)
{
	account.updateInterest();
	EXPECT_EQ(10500, account.getBalace());
}

TEST_F(AccountFixture, TenPercentInterest)
{
	account.setInterest(10);
	account.updateInterest();
	EXPECT_EQ(11000, account.getBalace());
}

TEST_F(AccountFixture, InterestAfterNyear)
{
	account.setInterest(10);
	int ret = account.getPredictInterest(3);
	int expected = 13310;
	EXPECT_EQ(expected, ret);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}