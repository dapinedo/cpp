//Programmer: Daniel Pinedo
//Contact: daniel_pinedo@elcamino.edu
//Date updated: 5/18/2017
//CSCI 1, Assignment #8: Arrays of Struct
//File: DMVTestWithArraysOfStruct.cpp

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// DESCRIPTION
/*
This program gives a multiple choice DMV test. Student enters 'A', 'B', 'C', or 'D'.
Program stores questions and answers from file, and student responses in three different arrays.
The questions are stored in a string array and read from a file.
The answers are stored in a char array and read from a file.
Student responses are recorded in another char array.
All arrays have the same length.
The answer and student response arrays are compared. Student score is computed.
Each question, answer from file, and student response is printed to screen.
If answer is correct, program prints "you answered this question correctly"
If answer is incorrect, program prints "you answered this question incorrectly"
*/

// GLOBAL VARIABLES
const int MAX = 20; //MAX is the maximum capacity of all arrays
//Grade: 23/23
// STRUCTS
struct Quiz
{
	string question;
	char key;
	char response;
};

// FUNCTION PROTOTYPES

/*
Function: void openInputFile
This function opens a file if file exists and has has some data in it.
It will be called for each file object opened in main()
*/
void openInputFile(ifstream & input, const string & message);

/*
Function: int fillQuestions
This function reads questions from the question file and fills an array with the questions, so there is
one question per array element. Function returns the logical array length.
*/
int fillQuestions(Quiz qz[], ifstream & in);

/*
Function: int fillAnswerKey
This function reads answers from the answers file and fills an array with the answer keys, one answer
per array element. Function returns the logical array length.
*/
int fillAnswerKeys(Quiz qz[], ifstream & inA);

/*
Function: int fillResponses
This function manages:
1.) presenting user questions
2.) getting and storing user response
3.) Returning logical array length
*/
void fillResponses(Quiz qz[], int len);

/*
Function: int gradeResponses
This function compares the answer key and response array elements and returns total number correct.
This function also takes argument 'int len' which is logical length of both arrays.
Function returns number of correct answers.
*/
int gradeResponses(const Quiz qz[], int len);

/*
Function: void printAnswersAndResponses
This function prints to screen questions, answer key, user response. Arguments include respective arrays
and logical length of all arrays.
*/
void printAnswersAndResponses(const Quiz qz[], int len);

/*
IOAA for main()

Input
N/A

Output
Main calls other functions which print to console. Main also indicates whether test passed/failed.

Analysis
percent = (score/number of questions)* 100

Algorithm
1.	Print "     * * * Driver's License Practice Exam * * *     ", end of line
2.	ifstream in // ifstream object to be bonded with input file(s)
3.	openInputFile(in, "questions") // Call to openFile function to get valid file for questions array
4.	Quiz qz[MAX] // Creation of empty struct Quiz
5.	int lenQ = fillQuestions(qz, in) // Filling the qz.question array
6.	in.close()// Closing ifstream object so that we can reuse it.
7.	openInputFile(in, "answers") // Call to openFile function to get valid file for answer key array
8.	
9.	int lenA = fillAnswerKeys(qz, in) // Filling the answer key array
10.	if(lenQ != lenA) then // handling the file error situation when number of questions and answer keys are not same.
11.		Print,"Number of questions and answers are different.", end of line
12.	
13.	    
14.	fillResponses(qz, lenQ) // Filling the user response array
15.	score = gradeResponses(qz, lenQ) // Grading user responses
16.	printAnswersAndResponses(qz, lenQ) // Printing question, answer key and user responses.
17.	Print,"You scored ", score, " points, out of maximum ", lenQ, " points.", end of line
18.	double percent = (double(score)/lenQ)*100
19.		if(percent >= 60.0) then
20.			Print,"You scored ",percent," % in the quiz.", end of line
21.			Print,"You passed the quiz.", end of line
22.		else
23.			Print,"You scored ",percent," % in the quiz.", end of line
24.			Print,"Sorry you failed the quiz.", end of line
25.		end if
26.	end if
27.	in.close()
28.	Print string(60,'-'), end of line
29.	Print "Goodbye", end of line
*/
int main()
{
	cout << "     * * * Driver's License Practice Exam * * *     " << endl;
	ifstream in; // ifstream object to be bonded with input file(s)
	openInputFile(in, "questions"); // Call to openFile function to get valid file for questions array
	Quiz qz[MAX]; // Creation of empty array of struct type Quiz
	int lenQ = fillQuestions(qz, in); // Filling the questions array
	in.close();// Closing ifstream object so that we can reuse it.
	openInputFile(in, "answer key"); // Call to openFile function to get valid file for answer key array
	int lenA = fillAnswerKeys(qz, in); // Filling the answer key array
	if (lenQ != lenA)
	{ // handling the file error situation when number of questions and answer keys are not same.
		cout << "Number of questions and answers are different." << endl;
	}
	else
	{
		fillResponses(qz, lenQ); // Filling the user response  array
		int score = 0;
		score = gradeResponses(qz, lenQ); // Grading user responses
		printAnswersAndResponses(qz, lenQ); // Printing question, answer key and user responses.
		cout << "You scored " << score << " points, out of maximum " << lenQ << " points." << endl;
		double percent = (double(score) / lenQ) * 100;
		if (percent >= 60.0){
			cout << "You scored " << percent << " % in the quiz." << endl;
			cout << "You passed the quiz." << endl;
		}
		else{
			cout << "You scored " << percent << " % in the quiz." << endl;
			cout << "Sorry you failed the quiz." << endl;
		}
	}
	in.close();
	cout << string(75, '*') << endl;
	cout << "Goodbye" << endl;
	return 0;
}

/*
Function IOAA void openFile(ifstream & input, const string & message)
This function opens a file if file exists and has has some data in it.
It will be called for each file object opened in main()

Function Input through Arguments
Name		Type		Remarks
input		ifstream	Ifstream object passed from main function not attached to an input file
message		string		Would have a value "questions" for questions file and "answers" for answers file

User Input During Function Execution
Name		Type		Remarks
In_File		string		File name either for questions file (if message value is questions) or for answers file

Function Output
Function returns to main function by reference the ifstream object bonded to input file

Analysis
None

Algorithm
1. bool done = false
2. string In_File = ""
//Loop to get the name of a file that truly exists
// and check that file is not empty.

3. while(!done)
4. input.clear()
5. Print,"Please input the name of the data file with ",message," to be read : "
6. getline(cin,In_File)
7. Print,"The file name entered is : ",In_File,end of line
8. input(In_File)
9. if(!input.is_open()) then
10. Print,"The file ",In_File," does not exist.", end of line
11. done =false
12. else
13. input.peek()//peek at the input file
14. if(input.eof()) then                   //If file is empty then the function eof() returns true
15. Print,"The file has no data in it", end of line
16. done = false
17. input.close()
18. else
19. done = true
20. end if
21. end if
22. end while
23. Print,"File ",In_File," opened and has data in it.",end of line
24. end of function
*/
//void openInputFile(ifstream & input, const string & message);
void openInputFile(ifstream & input, const string & message)
{
	bool done = false;
	string In_File = "";
	//Loop to get the name of a file that truly exists
	// and check that file is not empty.

	while (!done)
	{
		input.clear();
		cout << "Please input the name of the data file with "
			<< message << " to be read : ";
		getline(cin, In_File);
		cout << "The file name entered is : " << In_File << endl;
		input.open(In_File);

		if (input.fail()){
			cout << "The file " << In_File << " does not exist.\n";
			continue;
		}
		else
		{
			input.peek();//peek at the input file

			if (input.eof()){//If file is empty then the function eof() returns true
				cout << "The file has no data in it\n";
				input.close();
				continue;
			}
			else
			{
				done = true;
			}
		}
	}//end of while loop
	cout << "File " << In_File << " opened and has data in it." << endl;
}

/*
FUNCTION IOAA for int fillQuestions(Quiz qz[], ifstream & in)
This function reads questions from the question file and fills an array with the questions.
Function returns the logical array length.

INPUT: Arguments
Name			Type		Remarks
qz.question[]	string		Empty array of strings to contain questions in the questions file
in				ifstream &	the ifstream object bonded to questions file that has been already opened

INPUT: User
N/A

OUTPUT: Arguments
Name			Type		Remarks
qz.question     string      All questions copied to array from file
in              ifstream &
i               int         Function returns value for logical length of questions[]

ANALYSIS
N/A

Algorithm
1. i = 0
2. while(in.peek() != EOF && i<MAX)
2a.		string temp;
2b.		getline(in, temp, '$')
2c.		qz.question[i] = temp;
2d.		i = i + 1
3. end while
4.	return i
*/
int fillQuestions(Quiz qz[], ifstream & in)
{
	int i = 0;
	while (in.peek() != EOF && i<MAX)
	{
		string temp;
		getline(in, temp, '$');
		qz[i].question = temp;
		i++;
	}
	return i;
}

/*
Function IOAA for int fillAnswerKeys(Quiz qz[], ifstream & inA)
This function reads answers from the answers file and fills an array with the answer keys, one answer
per array element. Function returns the logical array length.

Function Input through Argument
Name			Type		Remarks
qz.key[]		bool		Empty array of boolean to contain answers in the answer file
inA				ifstream	the ifstream object bonded to answers file that has been already opened

User Input During Function Execution
None

Function Output
Function returns to main function by reference the filled array called answers and
ifstream object inA passed to it by reference

Analysis
None

Algorithm
1. i = 0
2.	while((inA.peek()) != EOF and and i<MAX)
3.		qz.key[i] <- inA
4.		i = i + 1
5.	end while
6.	return i
*/

int fillAnswerKeys(Quiz qz[], ifstream & inA)
{
	int i = 0;
	while (inA.peek() != EOF && i<MAX)
	{
		inA >> qz[i].key;
		i++;
	}
	return i;
}

/*
Function IOAA for void fillResponses(Quiz qz[], int len)
This function manages:
1.) presenting user questions
2.) getting and storing user response
3.) Returning logical array length

Function Input through Argument
Name			Type		Remarks
qz.question[]	string		filled array containing questions for true false quiz
qz.response[]	char		Unfilled array which will record user response entered as char
len			    int			Logical length of questions and responses array

User Input During Function Execution
User will input char response

Function Output
Function returns to main function by reference the filled user response array

Analysis
None

Algorithm
Print, "Please answer the questions as asked. Questions are multiple choice.", End of line
Print, "Enter Corresponding letter for correct answer 'A' 'B' C' or 'D'", End of line
for(i=0, i<lenQ , i = i + 1)
     print, qz.question[i], " : "
     response[i]<- 
end for
*/
void fillResponses(Quiz qz[], int len)
{
	cout << "Please answer the questions as asked. Questions are multiple choice.\n"
		<< "Enter corresponding letter for correct answer 'A' 'B' C' or 'D'"
		<< endl;
	char temp;
	for (int i = 0; i<len; ++i)
	{
		cout << qz[i].question << " : ";
		cin >> temp;
		qz[i].response = toupper(temp);
	}
}

/*
FUNCTION IOAA for int gradeResponses(const Quiz qz[], int len)
This function compares the answer key and response array elements and returns total number correct.
This function also takes argument 'int len' which is logical length of both arrays.
Function returns number of correct answers.

INPUT: Arguments
Name			Type		Remarks
qz.key[]		char		filled array containing answer key values for multiple choice quiz
qz.response[]	char		response array already filled with user response
len				int			Logical length of answers and responses array

INPUT: User
N/A

OUTPUT: Arguments
Name			Type		Remarks
score           int         Function returns number of correct answers

Analysis
N/A

Algorithm
1.  score = 0;
2.	for( i=0,  i<len,  i = i + 1)
3.		if(qz.key[i] == qz.response[i]) then
4.		      score = score + 1
5.		end if
6.	end for
7.	return score
*/
int gradeResponses(const Quiz qz[], int len)
{
	int score = 0;
	for (int i = 0; i<len; i++)
	{
		if (qz[i].key == qz[i].response){
			score++;
		}
	}
	return score;
}

/*
IOAA for function void printAnswersAndResponses(const Quiz qz[], int len)
Function Input through Argument
Name			Type		Remarks
qz.question[]	string		filled array containing questions for true false quiz
qz.key[]		char		filled array containing answer key values for true false quiz
qz.response[]	char		response array already filled with user response
len				int			Logical length of questions, answers and responses array

User Input During Function Execution
None

Function Output
Function outputs to console (for user feedback), the questions, correct answers, user answers

Analysis
None

Algorithm
1. Print "Now we give summary of all questions, answers, and your responses", end of line
2. for( i= 0, i<len,  i = i + 1)
3.		Print qz.question[i]
4.      Print "Correct answer = " qz.key[i]
5.		Print "Your answer = " qz.response[i]
9.      if (qz.key[i] == qz.response[i]) then
10.          Print "You got this question right"
11.     else Print "You for this question wrong"
12.     end if
13.     pause
14.     end function.
*/
void printAnswersAndResponses(const Quiz qz[], int len)
{
	cout << "Now we give summary of all questions, answers, and your responses" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << qz[i].question << endl;
		cout << "Correct Answer = " << qz[i].key << endl;
		cout << "Your Answer = " << qz[i].response << endl;
		if (qz[i].key == qz[i].response)
		{
			cout << "You got this question right" << endl;
		}
		else
		{
			cout << "You got this question wrong" << endl;
		}
		system("pause");
	}
	return;
}