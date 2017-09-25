/* Daniel Pinedo
 * CS 2 - Section 0140
 * assignment: 2, part 2 Prepwork
 * due: Sept. 20, 2017
 * assign2b_prepwork.cpp
 */


/*
flag = 1 means sort based on Account Number
flag = 2 means sort based on Last Name
flag = 3 means sort based on Loan Amount
*/
void bubbleSort (Mortgage data[], int recordcount, short flag) {
	for (size_t i = 0; i< recordcount; i++) {
			for (size_t j = 0; j< recordcount - 1 - i; j++) {
				if(flag == 1) { // sort on Account Number
					if(data[j].getAccountNum() > data[j+1].getAccountNum()) {
						// Swap whole struct members in the array
						Mortgage Temp;
						Temp = data[j];
						data[j] = data[j+1];
						data[j+1] = Temp;
					}
				}
				else if(flag == 2) { // sort on last name
					if(data[j].getLastname() > data[j+1].getLastname()) {
						// Swap whole struct members in the array
						Mortgage Temp;
						Temp = data[j];
						data[j] = data[j+1];
						data[j+1] = Temp;
					}
				}
				else if(flag == 3) { // sort on Loan Amount
					if(data[j].getLoanAmount() > data[j+1].getLoanAmount()) {
						// Swap whole struct members in the array
						Mortgage Temp;
						Temp = data[j];
						data[j] = data[j+1];
						data[j+1] = Temp;
					}
				}
			}// inner for loop
	}// outer for loop
}

/* 
Flag = 1 means sort and search based on Account Number
Flag = 2 means sort and search based on last name
*/
int linearSearch (Mortgage data[], Mortgage searchterm, int recordcount, short flag) {
	bubbleSort (data, recordcount, flag);
	for (int i = 0; i < recordcount; i++) {
		if (flag == 1) {
			if (data[i].getAccountNum() == searchterm.getAccountNum()) {
				return i;
			}
		}
		else if (flag == 2) {
			if (data[i].getLastname() == searchterm.getLastname()) {
				return i;
			}
		}
	}
	return -1;
}