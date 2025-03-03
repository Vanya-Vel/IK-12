#pragma once  // Захист від багаторазового включення заголовкового файлу

class Money
{
private:
	unsigned int first;  // Номінал купюри
	unsigned int second; // Кількість купюр

public:
	int GetFirst() const { return first; }  // Отримати номінал
	unsigned int GetSecond() const { return second; }  // Отримати кількість купюр

	void SetFirst(int value);  // Встановити номінал
	void SetSecond(unsigned int value);  // Встановити кількість купюр

	bool Init(int Denom, int NumOfDenom);  // Ініціалізація об'єкта з перевіркою правильності вхідних даних
	void Display() const;  // Вивід значень номіналу і кількості купюр на екран
	void Read();  // Зчитування значень з клавіатури

	int Summa();  // Обчислення загальної суми грошей
};
