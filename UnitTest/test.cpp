#include "gtest/gtest.h"
#include "../RockPaperScissors/Player.h"
#include "../RockPaperScissors/Round.h"
#include "../RockPaperScissors/GeneralConsts.h"

TEST(TestFunctionality, TestScissorWinsPaper) {
	std::shared_ptr<UserPlayer> PaperPlayer( new UserPlayer());
	PaperPlayer->setChoice(Choice::Papers);

	std::shared_ptr<UserPlayer> ScissorsPlayer(new UserPlayer());
	ScissorsPlayer->setChoice(Choice::Scissors);

	Round round(PaperPlayer, ScissorsPlayer);
	round.checkRoundWinner();

  EXPECT_EQ(PaperPlayer->getWinsCount(), 0);
  EXPECT_EQ(ScissorsPlayer->getWinsCount(), 1);
  EXPECT_EQ(round.getRoundResult(), Result::Player2Won);
}

TEST(TestFunctionality, TestTie) {
	std::shared_ptr<UserPlayer> PaperPlayer(new UserPlayer());
	PaperPlayer->setChoice(Choice::Papers);

	std::shared_ptr<UserPlayer> PaperPlayer2(new UserPlayer());
	PaperPlayer2->setChoice(Choice::Papers);

	Round round(PaperPlayer, PaperPlayer2);
	round.checkRoundWinner();

	EXPECT_EQ(PaperPlayer->getWinsCount(), 0);
	EXPECT_EQ(PaperPlayer->getWinsCount(), PaperPlayer2->getWinsCount());
	EXPECT_EQ(round.getRoundResult(), Result::Tie);
}

TEST(TestFunctionality, TestPaperkWinsRock) {
	std::shared_ptr<UserPlayer> RockPlayer(new UserPlayer());
	RockPlayer->setChoice(Choice::Rocks);

	std::shared_ptr<UserPlayer> PaperPlayer(new UserPlayer());
	PaperPlayer->setChoice(Choice::Papers);

	Round round(RockPlayer, PaperPlayer);
	round.checkRoundWinner();

	EXPECT_EQ(RockPlayer->getWinsCount(), 0);
	EXPECT_EQ(PaperPlayer->getWinsCount(), 1);
	EXPECT_EQ(round.getRoundResult(), Result::Player2Won);
}

TEST(TestFunctionality, TestRockWinsScissor) {
	std::shared_ptr<UserPlayer> RockPlayer(new UserPlayer());
	RockPlayer->setChoice(Choice::Rocks);

	std::shared_ptr<UserPlayer> ScissorsPlayer(new UserPlayer());
	ScissorsPlayer->setChoice(Choice::Scissors);

	Round round(RockPlayer, ScissorsPlayer);
	round.checkRoundWinner();

	EXPECT_EQ(RockPlayer->getWinsCount(), 1);
	EXPECT_EQ(ScissorsPlayer->getWinsCount(), 0);
	EXPECT_EQ(round.getRoundResult(), Result::Player1Won);
}

TEST(TestBasic, TestPlayerDefaultNoWins) {
	auto RockPlayer = new UserPlayer();
	RockPlayer->setChoice(Choice::Rocks);

	EXPECT_EQ(RockPlayer->getWinsCount(), 0);
}
