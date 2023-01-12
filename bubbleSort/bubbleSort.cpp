#include <iostream>//Include iostream library
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output
using namespace std;//Declare use of namespace



int main(){ 
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient
    
    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): ";//Show on screen for user to know what to input
    
    do{
        string x;
        cin >> x;//Get input from user 

        //Change all letters to lowercase 
        for(int i = 0; i < x.length(); i++){
            x[i] = tolower(x[i]);
        }

        //sort by age
        if(x == "age"){
            cout << "Case 1, sorting by Age" << endl;//Output that user chose to sort by age
            for (int y = 0; y < NUM_PATIENTS - 1; y++){
                for (int a = 0; a < NUM_PATIENTS - 1; a++){//Iterate for values to be compared
                    if (age[a] > age[a+1]){//Compare age values
                        //Swap values to match every person according to their age 
                        swap(age[a], age[a+1]);
                        swap(id[a], id[a+1]);
                        swap(sex[a], sex[a+1]);
                        swap(lastName[a], lastName[a+1]);
                        swap(firstName[a], firstName[a+1]);
                    }
                    else if (age[a] == age[a + 1]){ //Check if the age is the same for multiple people based on index 
                        if (strcmp(firstName[a], firstName[a+1]) > 0){ //Use firstName as a tiebreaker 
                            //Swap the category vales if tiebreaker needed according to first name
                            swap(age[a], age[a + 1]); 
                            swap(id[a], id[a + 1]);
                            swap(sex[a], sex[a + 1]);
                            swap(lastName[a], lastName[a + 1]);
                            swap(firstName[a], firstName[a + 1]); 
                        }
                    }
                }
            }
            break;
        }
        //sort by ID
        else if(x == "id"){
            cout << "Case 2, sorting by ID" << endl;//Output that user chose to sort by ID
            for (int y = 0; y < NUM_PATIENTS - 1; y++){
                for (int a = 0; a < NUM_PATIENTS - 1; a++){//Iterate for values to be compared
                    if (strcmp(id[a], id[a+1]) > 0){//Compare ID values
                        //Swap values to match every person according to their ID
                        swap(age[a], age[a + 1]); 
                        swap(id[a], id[a + 1]);
                        swap(sex[a], sex[a + 1]);
                        swap(lastName[a], lastName[a + 1]);
                        swap(firstName[a], firstName[a + 1]); 
                    }
                    else if (strcmp(id[a], id[a+1]) == 0){//Check if the ID is the same for multiple people based on index 
                        if (strcmp(firstName[a], firstName[a+1]) > 0){ //Use firstName as a tiebreaker
                            //Swap the category vales if tiebreaker needed according to first name
                            swap(age[a], age[a + 1]);  
                            swap(id[a], id[a + 1]);
                            swap(sex[a], sex[a + 1]);
                            swap(lastName[a], lastName[a + 1]);
                            swap(firstName[a], firstName[a + 1]); 
                        }
                    }
                }
            
            }
            break;
        }
        //sort by sex
        else if(x == "sex"){
            cout << "Case 3, sorting by Sex" << endl;//Output that user chose to sort by sex
            for (int y = 0; y < NUM_PATIENTS - 1; y++){
                for (int a = 0; a < NUM_PATIENTS - 1; a++){//Iterate for values to be compared
                    if (sex[a] == 'm' && sex[a+1] == 'f' ){//Compare sex values
                        //Swap values to match every person according to their age 
                        swap(age[a], age[a + 1]); 
                        swap(id[a], id[a + 1]);
                        swap(sex[a], sex[a + 1]);
                        swap(lastName[a], lastName[a + 1]);
                        swap(firstName[a], firstName[a + 1]); 
                    }
                    else if (sex[a] == 'm' && sex[a+1] == 'm'){ //Check if the sex is male for multiple people based on index 
                        if (strcmp(firstName[a], firstName[a+1]) > 0){ //Use firstName as a tiebreaker
                            //Swap the category vales if tiebreaker needed according to first name
                            swap(age[a], age[a + 1]); 
                            swap(id[a], id[a + 1]);
                            swap(sex[a], sex[a + 1]);
                            swap(lastName[a], lastName[a + 1]);
                            swap(firstName[a], firstName[a + 1]); 
                        }
                    }
                    else if (sex[a] == 'f' && sex[a+1] == 'f'){ //Check if the sex is female for multiple people based on index
                        if (strcmp(firstName[a], firstName[a+1]) > 0){ //Use firstName as a tiebreaker
                            //Swap the category vales if tiebreaker needed according to first name
                            swap(age[a], age[a + 1]); 
                            swap(id[a], id[a + 1]);
                            swap(sex[a], sex[a + 1]);
                            swap(lastName[a], lastName[a + 1]);
                            swap(firstName[a], firstName[a + 1]); 
                        }
                    }
                }
            }
            break;
        }
        //sort by last name
        else if(x == "last"){
            cout << "Case 4, sorting by Last Name" << endl;//Output that user chose to sort by last name
            for (int y = 0; y < NUM_PATIENTS - 1; y++){ 
                for (int a = 0; a < NUM_PATIENTS - y - 1; a++){ //Iterate for values to be compared
                    if (strcmp(lastName[a], lastName[a+1]) > 0){ // compare last name values
                        //Swap values to match every person according to their last name 
                        swap(age[a], age[a + 1]); 
                        swap(id[a], id[a + 1]);
                        swap(sex[a], sex[a + 1]);
                        swap(lastName[a], lastName[a + 1]);
                        swap(firstName[a], firstName[a + 1]); 
                    }
                    else if (strcmp(lastName[a], lastName[a+1]) == 0){ //Check if the last name is the same for multiple people based on index
                        if (strcmp(firstName[a], firstName[a+1]) > 0){ //Use firstName as a tiebreaker
                            //Swap the category vales if tiebreaker needed according to first name
                            swap(age[a], age[a + 1]); 
                            swap(id[a], id[a + 1]);
                            swap(sex[a], sex[a + 1]);
                            swap(lastName[a], lastName[a + 1]);
                            swap(firstName[a], firstName[a + 1]); 
                        }
                    }
                }
            }
            break;
        }
        //sort by first name
        else if(x == "first"){
            cout << "Case 5, sorting by First Name" << endl;//Output that user chose to sort by first name
            for (int y = 0; y < NUM_PATIENTS - 1; y++){ 
                for (int a = 0; a < NUM_PATIENTS - y - 1; a++){ //Iterate for values to be compared
                    if (strcmp(firstName[a], firstName[a+1]) > 0){ // compare first name values 
                        //Swap values to match every person according to their first name
                        swap(age[a], age[a + 1]); 
                        swap(id[a], id[a + 1]);
                        swap(sex[a], sex[a + 1]);
                        swap(lastName[a], lastName[a + 1]);
                        swap(firstName[a], firstName[a + 1]); 
                    }
                }
            }
            break;
        }
        //If output is not permitted tell user to input a proper value  
        else{
            cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex: ";
        }
        } while (true);



    //Show on screen the age information (tabular output)
    cout << setw(11) << "Age:";
    for (int y = 0; y < NUM_PATIENTS; y++){//Iterate for every person
        cout << setw(11) << age[y];
    } 
    cout << endl;//Next line

    //Show on screen the ID information (tabular output)
    cout << setw(11) << "ID:";
    for (int y = 0; y < NUM_PATIENTS; y++){//Iterate for every person
        cout << setw(11) << id[y];
    } 
    cout << endl;//Next line

    //Show on screen the first name information (tabular output)
    cout << setw(11) << "First Name:";
    for (int y = 0; y < NUM_PATIENTS; y++){//Iterate for every person
        cout << setw(11) << firstName[y];
    } 
    cout << endl;//Next line

    //Show on screen the last name information (tabular output)
    cout << setw(11) << "Last Name:";
    for (int y = 0; y < NUM_PATIENTS; y++){//Iterate for every person
        cout << setw(11) << lastName[y];
    } 
    cout << endl;//Next line

    //Show on screen the sex information (tabular output)
    cout << setw(11) << "Sex:";
    for (int y = 0; y < NUM_PATIENTS; y++){//Iterate for every person
        cout << setw(11) << sex[y];
    } 
    cout << endl;//Next line

    return 0;
}