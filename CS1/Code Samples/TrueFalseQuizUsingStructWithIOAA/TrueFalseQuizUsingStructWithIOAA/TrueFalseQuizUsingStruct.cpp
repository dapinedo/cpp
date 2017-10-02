/*
Written by : Satish Singhal
Date: 26 July 2016
E-Mail: ssinghal@elcamino.edu
This is the modified version of true/false quiz program where only one struct array is used
rather than three atomic arrays arrays.
This program gives a student a true/false quiz. Student enters 1 for true answer and 0 (zero) for the
false answer. Program stores all three: questions, answers, and student responses in a struct array.
Questions and answer keys are read from one file.
Each question is followed by the correct answer key as 1 or 0. Value 1 is true and 0 is false.
The structure of file is below:
Earth is flat?
0
Moon is a satellite of Earth.
1
The answer and student responses stored in each struct member in the array are compared. Student score is computed.
If student scores 60% or more the message is given that student passed. Otherwise
message is given that student failed.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//MAX is the maximum capacity of the struct array Quiz defined below
const int MAX = 10;
/*
 IOAA struct Quiz
 ******************
 struct Members
 ------------------
 Name           Data Type           Remarks
 ...............................................................................................
 question       string              Stores the question part of true false quiz
 answer         bool                Stores the boolean value of answer key to the question
 response       bool                Stores the boolean value of the user response to the question
 -------------------------------------------------------------------------------------------------
 pseudocode representation of struct
 
 struct Quiz
    question
    answer
    response
 end struct
 */
struct Quiz{
	string question;
	bool answer;
	bool response;
};
/*
 Opens and returns by reference the ifstream object bonded to data input file
 whose structure is shown earlier in section in first part of this document.
 IOAA is shown above the function definition later.
 */
void openInputFile(ifstream & input);
//fillQuizArray function fills the question and answer members of each
//struct Quiz array element, from input file bonded to the ifstream object in and returns the logical array
//length by return mechanism.
int fillQuizArray(Quiz qz[], ifstream & in);
// Optional function to print the question and answer members of array of struct Quiz read
//from the input file.
void printQuizArray(const Quiz qz[], int len);
//printQuestionsAndGetResponses manages the followings:
//1. Presenting the user the questions sequentially from the question part of the struct from array qz[].
//2. Getting user response to each question and storing them in a response member of corresponding struct
//element in the struct array.
void  printQuestionsAndGetResponses(Quiz qz[], int len);
/*
 Function scoreTest takes the struct array qz[] where each array member in the logical 
 length has the struct with fields question, answer, and response populated. 
 Function iterates through the struct array and compares for each array member
 the answer and response fields. It two match then the score variable is incremented
 by one. Function returns the number of points scored by the test taker.
 */
int scoreTest(Quiz qz[], int len);
//printAnswersAndResponses function prints questions, correct answer, user response.
void printAnswersAndResponses(const Quiz qz[], int len);
/*
 IOAA for main function
 Function Input through Argument
 None
 
 User Input During Function Execution
 None
 
 Function Output
 Function calls other functions as illustrated in algorithm below
 Function outputs to console the score and percentage obtained in test
 Function also outputs whether user passed or failed the test.
 
 Analysis
 percent = (score/number of questions)* 100
 
 Algorithm
 0. Set formatting flags to format floating point, and boolean data output.
 1.	Print,"This program will deliver a true/false quiz, record your responses and grade them.", end of line
 2.	ifstream in // ifstream object to be bonded with input file(s)
 3.	openFile(in) // Call to openFile function to get valid file for questions and answers
 4.	Quiz qz[MAX] // Creation of empty struct array
 5.	int len = fillQuizArray(qz, in) // Filling the struct array with questions and answers
 6. print "Please answer the questions for the quiz. Enter 1 for true answer and number zero (0) for false.", end of line
 7. printQuestionsAndGetResponses(qz, len);
 8. int points = scoreTest(qz, len)// Grading user responses
 9. Print, "You scored ", points, " points out of total " , len,  " points." , end of line
 10.	double percent = 100*(double(points)/len)
 
 11.		if(percent >= 60.0) then
 12.			Print,"You scored ",percent," % in the quiz.", end of line
 13.			Print,"You passed the quiz.", end of line
 14.		else
 15.			Print,"You scored ",percent," % in the quiz.", end of line
 16.			Print,"Sorry you failed the quiz.", end of line
 17.		end if
 18.	end if
 19.	printAnswersAndResponses(qz, len) // Printing question, answer key and user responses.
 20.	in.close()
 21.	Print "Goodbye", end of line
 22. end of function
 */
int main(){
	cout << fixed << showpoint << setprecision(2);
	cout << boolalpha;
	cout << "This program will deliver a true/false quiz, record your responses and grade them." << endl;
	ifstream in;
	openInputFile(in);
	Quiz qz[MAX];
	int len = fillQuizArray(qz, in);
	cout << "Please answer the questions for the quiz. Enter 1 for true answer and number zero (0) for false." << endl;
	//printQuizArray(qz, len);
	printQuestionsAndGetResponses(qz, len);
	int points = scoreTest(qz, len);
	cout << "You scored " << points << " points out of total " << len << " points." << endl;

	double percent = 100 * double(points) / len;

	if (percent >= 60.0){
		cout << "You passed the test." << endl;
	}
	else
    {
		cout << "You failed the test." << endl;
	}

	printAnswersAndResponses(qz, len);
    in.close();
    cout<<"Goodbye."<<endl;
	return 0;
}
/*
 IOAA for function void printAnswersAndResponses(const Quiz qz[], int len)
 Function Input through Argument
 Name			Type       Remarks
 qz[]           Quiz		filled array containing questions, answers, and responses
 len			int		Logical length of questions, answers and responses array
 
 User Input During Function Execution
 None
 
 Function Output
 Function outputs to console (for user feedback), the questions, correct answers, user answers
 
 Analysis
 None
 
 Algorithm
 1. Print,"*****************************************************", end of line
 2.	Print,"Here are correct answers and your responses.", end of line
 3.	Print,"*****************************************************", end of line
 4.	Print,setw(55),left,"Question",setfill(' '),setw(18),left,"Correct Answer",setfill(' '),left,setw(15),"Your Response", end of line
5.Print,"--------------------------------------------------------------------------------------------------------", end of line
 
 7.	for( i= 0, i<len,  i = i + 1)
 8.		Print,setw(55),left,qz[i].question,setfill(' '),setw(18),left,qz[i].answer,setfill(' '),setw(15),left,qz[i].response, end of line
 9.	if (qz[i].answer == qz[i].response) then
 10. print, "You answered this question correctly.", end of line
 11. else
 12. print, "You answered this question wrongly." , end of line
 13. end if
 14. print,  "***********************************************************************************************************" , end of line
 15. system("pause")
 16. print, "************************************************************************************************************" , end of line
 17.	end for
 
 18.	Print,"--------------------------------------------------------------------------------------------------------", end of line
 19. end of function
 */
void printAnswersAndResponses(const Quiz qz[], int len){
	cout << "*****************************************************" << endl;
	cout << "Here are correct answers and your responses." << endl;
	cout << "*****************************************************" << endl;
	cout << setw(55) << left << "Question" << setfill(' ') << setw(18) 
		<< left << "Correct Answer" << setfill(' ') << left << setw(15) 
		<< "Your Response" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i<len; i++){
		cout << setw(55) << left << qz[i].question << setfill(' ') 
			<< setw(18) << left << qz[i].answer << setfill(' ') 
			<< setw(15) << left << qz[i].response << endl;
		if (qz[i].answer == qz[i].response){
			cout << "You answered this question correctly." << endl;
		}
		else{
			cout << "You answered this question wrongly." << endl;
		}
		cout << "***********************************************************************************************************" << endl;
		//system("pause");//Not available on Mac
		cout << "************************************************************************************************************" << endl;
	}

	cout << "--------------------------------------------------------------------------------------------------------" << endl;
}
/*
 IOAA for function int scoreTest(Quiz qz[], int len)
 Function Input through Argument
 Name			Type		Remarks
 qz[]           Quiz		filled array containing answer, and responses for each struct member of array
 len			int		Logical length of qz[] array
 
 User Input During Function Execution
 None
 
 Function Output
 Function returns to caller function by a return mechanism the correct number of answers by 
 the user in true false quiz
 
 Analysis
 None
 
 Algorithm
 1.  score = 0;
 2.	for( i=0,  i<len,  i = i + 1)
 3.		if(qz[i].answers[i] == qz[i].response[i]) then
 4.		score = score + 1
 5.		end if
 6.	end for
 7.	return score
 8. end of function
 */
int scoreTest(Quiz qz[], int len){
	int score = 0;

	for (int i = 0; i<len; i++){
		if (qz[i].answer == qz[i].response){
			score++;
		}
	}

	return score;
}
/*
 IOAA for function void printQuestionsAndGetResponses(Quiz qz[], int len)
 Function Input through Argument
 Name			Type		Remarks
 qz[]           Quiz		filled array containing questions but empty spaces for response field
 len            int		Logical length of qz[] array
 
 User Input During Function Execution
 User will input either 1 for the true answer or 0 for false answer
 
 Function Output
 Function returns to main function by reference the qz[] array in which user response is recorded in
 each sruct member in the response field.
 
 Analysis
 None
 
 Algorithm
1. for( i=0, i<len , i = i + 1)
2. print, qz[i].question, " : "
3. qz[i].response[i]<-
4. end for
5. end of function
 */
void printQuestionsAndGetResponses(Quiz qz[], int len){
	for (int i = 0; i<len; i++){
		cout << qz[i].question << endl;
		cin >> qz[i].response;
	}
}
/*
 IOAA for function void printQuizArray(const Quiz qz[], int len)
 Function Input through Argument
 Name			Type		Remarks
 qz[]           Quiz		filled array containing questions and answer fields
 len            int		Logical length of qz[] array
 
 User Input During Function Execution
 None
 
 Function Output
 Function prints to console (one line each) questions followed by the answer
 
 Analysis
 None
 
 Algorithm
 0. Set boolean data formatting flag
 1. for( i=0, i<len , i = i + 1)
 2. print, qz[i].question, end of line
 3. print, qz[i].answer, end of line
 4. end for
 5. end of function
*/
void printQuizArray(const Quiz qz[], int len){
	cout << boolalpha;

	for (int i = 0; i<len; i++){
		cout << qz[i].question << endl;
		cout << qz[i].answer << endl;
	}
}
/*
 IOAA for function int fillQuizArray(Quiz qz[], ifstream & in)
 Function Input through Arguments
 
 Name		Type		Remarks
 qz[]		Quiz		Empty array of Quiz struct
 in		ifstream	The ifstream object bonded to file that has been already opened
 
 User Input During Function Execution
 None
 
 Function Output
 Function returns to main function by reference the filled array called qz[] and
 ifstream object in passed to it by reference. The question and answer fields of each array
 member are populated by the function as read from the file.
 
 Analysis
 None
 
 Algorithm
 1. count = 0
 2. ch = ' '
 2.	while((ch = in.peek()) != EOF and and count<MAX)
 3.		temp = ""
 4.		getline(in, temp)
 5.		qz[count].questions = temp;
 6. 	bool ans = false
 7.		ans <- in
 8.     qz[count].answer = ans
 9.     in.ignore(128, '\n');
 10.	count = count + 1
 11.	end while
 12. return count
 13. end of function
 */
int fillQuizArray(Quiz qz[], ifstream & in){
	int count = 0;
	char ch = ' ';

	while ((ch = in.peek()) != EOF && count<MAX){
		string temp = "";
		getline(in, temp);
		qz[count].question = temp;
		bool ans = false;
		in >> ans;
		in.ignore(128, '\n');
		qz[count].answer = ans;
		count++;
	}
	return count;
}
/*
 IOAA for function void openInputFile(ifstream & input)
 Function Input through Arguments
 Name		Type		Remarks
 input	ifstream	Ifstream object passed from main function not attached to an input file
 
 
 User Input During Function Execution
 Name		Type		Remarks
 In_File	string	File name either for input file
 
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
 5. Print,"Please input the name of the data file to be read : "
 6. getline(cin,In_File)
 7. Print,"The file name entered is : ",In_File,end of line
 8. input.open(In_File)
 9. if(input.fail()) then
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
void openInputFile(ifstream & input){
	bool done = false;
	string In_File = "";
	//Loop to get the name of a file that truly exists
	// and check that file is not empty.

	while (!done){
		input.clear();
		cout << "Please input the name of the data file to be read : ";
		getline(cin, In_File);
		cout << "The file name entered is : " << In_File << endl;
		input.open(In_File);

		if (input.fail()){
			cout << "The file " << In_File << " does not exist.\n";
			done = false;
		}
		else{
			input.peek();//peek at the input file

			if (input.eof()){//If file is empty then the function eof() returns true
				cout << "The file has no data in it\n";
				done = false;
				input.close();
			}
			else{
				done = true;
			}
		}
	}//end of while loop
	cout << "File " << In_File << " opened and has data in it." << endl;
}