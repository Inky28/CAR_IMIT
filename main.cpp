/*
Реалізувати систему по транспорту:

	Реалізувати обєкти легкових та вантажних автомобілів та маршуток

	Кожен з обєктів має мати Вагу, Бренд, Модель, Рік, обєм двигуна.

		Легкови автомобіль має мати:  кількість пасажирів, масив з комплектацією машини (Клімат контроль, АБС, захисні подушки ...)
		Грузова машина має мати: Максимальну вагу для перевезення
		Автобус має мати: номер перевезення, максимальну кількість пасижирів.

Реалізувати меню через яке можна буде додавати та переглядати списки з транспортом в системі.

Для обєкті мають бути реалізовані методи для виведення, конструктори та інкапсуляція.
*/

#include <iostream>
#include <string>
#define SIZE 10
#define OTHER cout<<"=====================================\n";

using namespace std;

class ParametersCar
{
private:

protected:
	int weight;
	int year;
	float volume;
	string brend;
	string model;
public:

	void SetWeight(int weight)
	{
		this->weight = weight;
	}
	int GetWeight()
	{
		return this->weight;
	}

	void SetYear(int year)
	{
		if (year > 2020)
		{
			cout << "Error\n";
		}
		else
		{
			this->year = year;
		}
	}
	int GetYear()
	{
		return this->year;
	}

	void SetVolume(float volume)
	{
		this->volume = volume;
	}
	float GetVolume()
	{
		return this->volume;
	}

	void SetBrend(string brend)
	{
		this->brend = brend;
	}
	string GetBrend()
	{
		return this->brend;
	}

	void SetModel(string model)
	{
		this->model = model;
	}
	string GetModel()
	{
		return this->model;
	}

	ParametersCar(int weight, int year, float volume, string brend, string model)
	{
		this->weight = weight;
		this->year = year;
		this->volume = volume;
		this->brend = brend;
		this->model = model;
	}

	ParametersCar()
	{
		this->weight = 0;
		this->year = 0;
		this->volume = 0;
		this->brend = "NONAME";
		this->model = "NONAME";
	}

	void Print()
	{
		cout << "Weight car : " << this->weight << endl;
		cout << "Year car : " << this->year << endl;
		cout << "Engine capacity : " << this->volume << endl;
		cout << "Brend car : " << this->brend << endl;
		cout << "Model car : " << this->model << endl;
	}
};

class Bus : public ParametersCar
{
private:
	int numberBus;
	int maxPassengers;
public:

	Bus(int weight, int year, float volume, string brend, string model) : ParametersCar(weight, year, volume, brend, model)
	{
		this->numberBus = 0;
		this->maxPassengers = 0;
	}

	Bus(int numberBus, int maxPassengers, int weight, int year, float volume, string brend, string model) : ParametersCar(weight, year, volume, brend, model)
	{
		this->numberBus = numberBus;
		this->maxPassengers = maxPassengers;
	}

	void SetNumberBus(int numberBus)
	{
		if (numberBus > 50)
		{
			cout << "Error\n";
		}
		else
		{
			this->numberBus = numberBus;
		}
	}
	int GetNumberBus()
	{
		return this->numberBus;
	}

	void SetMaxPassengers(int maxPassengers)
	{
		if (maxPassengers > 40)
		{
			cout << "Error\n";
			this->maxPassengers = 40;
		}
		else
		{
			this->maxPassengers = maxPassengers;
		}
	}

	void Print()
	{
		ParametersCar::Print();
		cout << "Number bus : " << this->numberBus << endl;
		cout << "Max amount Passengers in the bus : " << this->maxPassengers << endl;
	}
};

class SimpleCar : public ParametersCar
{
private:
	int countPassengers;
	string kitCar[SIZE];
public:

	SimpleCar(int weight, int year, float volume, string brend, string model) : ParametersCar(weight, year, volume, brend, model)
	{
		this->countPassengers = 0;
		this->kitCar[SIZE] = {};
	}

	void SetKitCar(string kitCar[SIZE])
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			this->kitCar[i] = kitCar[i];
		}
	}

	SimpleCar(int countPassengers, string kitCar[SIZE], int weight, int year, float volume, string brend, string model) : ParametersCar(weight, year, volume, brend, model)
	{
		this->countPassengers = countPassengers;
		SetKitCar(kitCar);
	}

	void SetCountPassengers(int countPassengers)
	{
		if (countPassengers > 5)
		{
			cout << "Error\n";
		}
		else
		{
			this->countPassengers = countPassengers;
		}
	}

	int GetCountPassengers()
	{
		return this->countPassengers;
	}
	void ShowKitCar()
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			if (kitCar[i] == "")
				break;

			cout << "Kit CAR: " << this->kitCar[i] << endl;
		}
	}

	void Print()
	{
		ParametersCar::Print();
		cout << "Count Passengers in the car : " << this->countPassengers << endl;
		ShowKitCar();
	}
};

class Truck : public ParametersCar
{
private:
	float maxWeight;
public:
	Truck(int weight, int year, float volume, string brend, string model) : ParametersCar(weight, year, volume, brend, model)
	{
		this->maxWeight = 0;
	}

	Truck(float maxWeight, int weight, int year, float volume, string brend, string model) : ParametersCar(weight, year, volume, brend, model)
	{
		this->maxWeight = maxWeight;
	}

	void SetMaxWeight(float maxWeight)
	{
		if (maxWeight > 3000)
		{
			cout << "Error\n";
			this->maxWeight = 3000;
		}
		this->maxWeight = maxWeight;
	}

	float GetMaxWeight()
	{
		return this->maxWeight;
	}

	void Print()
	{
		ParametersCar::Print();
		cout << "MAX Weight car : " << this->maxWeight << endl;
	}
};



int main()
{
	string KitCar[SIZE]
	{
		"ABS",
		"Nitro",
		"Airbags",
		"Computer",
		"Sports mode",
		"All-wheel drive",
		"Leather interior",
		"Air conditioning",
		"Automatic transmission",
		"Artificial Intelligence",
	};

	Bus firstBus(34, 12, 2300, 2015, 15.6, "Bogdan", "SLK-344");
	firstBus.Print();

	OTHER

		SimpleCar firstCar(3, KitCar, 1500, 2019, 10.2, "Toyota", "BBL-1");
	firstCar.Print();

	OTHER

		Truck firstTruck(2600, 1950, 2010, 30.2, "BELUGA", "BNG-954");
	firstTruck.Print();


	return 0;
}