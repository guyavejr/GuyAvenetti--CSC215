#include <iostream>
#include <string>

class UserCredentials 
{
public:
	std::string username1 = "goodguy";
	std::string password1 = "goodguy";
	std::string username2 = "badguy";
	std::string password2 = "badguy";
	double balance1 = 10000.0;
	double balance2 = 0.0;
};

int main()
{
	UserCredentials credentials;

	std::string username, password;
	double depositAmount;
	char choice;

	bool loggedIn = false;
	bool user2LoggedInLast = false;

	while (true) 
	{
		loggedIn = false;

		while (!loggedIn)
		{
			std::cout << "Enter Username:  ";
			std::cin >> username;
			std::cout << "Enter Password:  ";
			std::cin >> password;

			if (username == credentials.username1 && password == credentials.password1)
			{
				std::cout << "Login successful. Welcome Good Guy!" << std::endl;
				loggedIn = true;

				std::cout << "Your current balance is: $" << credentials.balance1 << std::endl;

				if (user2LoggedInLast == true)
				{
					do
					{
						std::cout << "Enter deposit amount for Good Guy: $";
						std::cin >> depositAmount;

						if (depositAmount > 0)
						{
							credentials.balance2 += depositAmount;
							std::cout << "Your Deposit is Successful. Your new balance is: $" << credentials.balance1 << std::endl;
						}
						else if (depositAmount < 0)
						{
							std::cout << "Invalid deposit amount." << std::endl;
						}

						std::cout << "Do you want to deposit again? (y/n): ";
						std::cin >> choice;
					} while (depositAmount != 0 && (choice == 'y' || choice == 'Y'));
					
				}
				else
				{
					do
					{
						std::cout << "Enter deposit amount for Good Guy: $";
						std::cin >> depositAmount;

						if (depositAmount > 0)
						{
							credentials.balance1 += depositAmount;
							std::cout << "Deposit successful for Good Guy. Their new balance is: $" << credentials.balance1 << std::endl;
						}
						else if (depositAmount < 0)
						{
							std::cout << "Invalid deposit amount." << std::endl;
						}

						std::cout << "Do you want to deposit again? (y/n): ";
						std::cin >> choice;
					} while (depositAmount != 0 && (choice == 'y' || choice == 'Y'));
				}
			}
			else if (username == credentials.username2 && password == credentials.password2)
			{
				do
				{
					if (user2LoggedInLast == false)
					{
						std::cout << "Login successful for Bad Guy!" << std::endl;
						loggedIn = true;
						
						std::cout << "Your current balance is: $" << credentials.balance2 << std::endl;
					}
					else if (user2LoggedInLast == true)
					{
						std::cout << "Login successful for Bad Guy!" << std::endl;
						loggedIn = true;
						user2LoggedInLast = false;
						credentials.balance2 += credentials.balance1;
							credentials.balance1 = 0;
						std::cout << "Your current balance is: $" << credentials.balance2 << std::endl;
					}
					std::cout << "Enter deposit amount for Bad Guy: $";
					std::cin >> depositAmount;

					if (depositAmount < 288222255)
					{
						credentials.balance2 += depositAmount;
						std::cout << "Your Deposit is successful. Your new balance is: $" << credentials.balance2 << std::endl;
					}
					else if (depositAmount == 288222255)
					{
						user2LoggedInLast = true;
						std::cout << "The ATTACK has been deployed" << std::endl;
					}

					std::cout << "Do you want to deposit again? (y/n): ";
					std::cin >> choice;
				} while (depositAmount != 0 && (choice == 'y' || choice == 'Y'));
			}
			else
			{
				std::cout << "Login failed. Invalid credentials." << std::endl;
			}
		}
	char again;
	std::cout << "Do you want to log in again? (y/n): ";
	std::cin >> again;

	if (again != 'y' && again != 'Y')
		{
			break;
		}
	}

	return 0;
}