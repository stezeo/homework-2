#include <iostream>
#include <ostream>
#include <string>
#include<iomanip>
#include<fstream>
#include "json.hpp"
#include<list>
#include<iterator>

using namespace std;

void drawline();



//recipe struct
struct recipeStruct
{
	string nameStruct;
	 vector<string> ingredientStruct;
};
void from_json(nlohmann::json const& json, recipeStruct& pple)
{
	pple.nameStruct = json.at("name").get<string>();
	pple.ingredientStruct = json.at("ingredients").get<vector<string>>();	
}




//ingredient struct
struct ingredientStruct
{
	string nameStruct;
	int quantityStruct;
	int priceTypeStruct;
};
void from_json(nlohmann::json const& json, ingredientStruct& ingred)
{
	ingred.nameStruct = json.at("name").get<string>();
	ingred.quantityStruct = json.at("quantity").get<int>();
	ingred.priceTypeStruct = json.at("priceType").get<int>();
}


//price struct
struct pricesStruct
{
	int idStruct;
	int priceStruct;
};
void from_json(nlohmann::json const& json, pricesStruct& price)
{
	price.idStruct = json.at("id").get<int>();
	price.priceStruct = json.at("price").get<int>();
}






int main()
{

	// for the price
	ifstream price{ "prices.json", ifstream::binary };
	nlohmann::json pricesJson;
	price >> pricesJson;
	price.close();
	vector<pricesStruct> pricesVect = pricesJson;


	// for the ingredient
	ifstream ingredient{ "ingredients.json", ifstream::binary };
	nlohmann::json ingredientsJson;
	ingredient >> ingredientsJson;
	ingredient.close();
	vector<ingredientStruct> ingredientVect = ingredientsJson;

	//for the recipe
	ifstream recipe{ "recipes.json", ifstream::binary };
	nlohmann::json recipeJson;
	recipe >> recipeJson;
	recipe.close();
	/*vector<recipeStruct> recipeVect = recipeJson;*/
	vector<recipeStruct> recipesVect = recipeJson;




	cout << "WELCOME" << endl;
	cout << "OUR RECIPE and the ingredient" << endl;

	drawline();
	cout << endl;

	for (auto reci : recipesVect)
	{
		cout << "}  " << reci.nameStruct << ": ";
		for (auto& j : reci.ingredientStruct)
			cout << j << ", ";
		cout << endl;
	}

		cout << "please enter your choice of pizza" << endl;
		string  PizzaTypeStr;
		getline(cin, PizzaTypeStr);
		
		
		bool logout = true;   // program is on as the user doesnot end it


	// check if pizza name input is in pizza list
		bool check = false;
		for (auto reci : recipesVect) 
		{
			if (reci.nameStruct == PizzaTypeStr) 
			{
				check = true;
				break;
			}
		}


		if (check == false) {
			cout << "This pizza is not in the list, please try again." << endl;
			return 0;
		}
		else
			cout << "Ok, you want to buy a pizza " << PizzaTypeStr << ", which is in our pizza list!" << endl;
		cout << endl;
		

	
	




void drawline()
{
	int lenght = 80;
	char lineTypechar;
	lineTypechar = '*';
	for (int i = 0; i < lenght; i++)
		cout <<lineTypechar;
}



