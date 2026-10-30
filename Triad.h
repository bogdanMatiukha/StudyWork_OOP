#pragma once

class Triad
{
protected:
	int first;
	int second;
	int third;

public:
	Triad(int first = 0, int second = 0, int third = 0);

	virtual void increaseFirst();
	virtual void increaseSecond();
	virtual void increaseThird();

	virtual void print() const;

	virtual ~Triad() = default;

};

class Time : public Triad
{
public:
	Time(int hours = 0, int minutes = 0, int seconds = 0);

	void increaseFirst() override;
	void increaseSecond() override;
	void increaseThird() override;

	void increaseSeconds(int seconds);
	void increaseMinutes(int minutes);

	void print() const override;

};