//Mason Miller
//millerm30@mailbox.winthrop.edu

import java.io.*;
import java.util.*;

public class WordFind
{
    public static void main(String[] args) throws FileNotFoundException, IOException
    {
        int counter = 0;
        try
        {
            String testArg = args[0];
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println(e);
            System.out.print("No file passed as argument to populate array. Usage is: WordFind [fileToPopulateArray] [fileWithWordList]");
            System.exit(99);
        }

        String searchName = args[0];
        String listName;
        File cashierSearch = new File(searchName);                          //file to read values from
        char[][] readArray = readWordSearch.populateArray(cashierSearch);   //declare array to store values
        searchWord.R = readArray.length;                                    //set Row and Column values for search function to max row and max column values of array.
        searchWord.C = readArray[0].length;

        if(args.length == 1)
        {
            listName = null;
        }
        else
        {
            listName = args[1];
        }

        if(listName != null)
        {
            File cashierList = new File(listName);
            Scanner List = new Scanner(cashierList);
            String word;
            while(List.hasNext())                           //while list not end of file
            {
                word = List.next();                         //"parse" words in string. will iterate through each line until newline character is found.
                {
                for(int i = 0; i < word.length(); i++)
                {
                    if(!(Character.isUpperCase(word.charAt(i)) || (Character.isLowerCase(word.charAt(i)))))     //check to make sure each character in given string to search for is either
                    {                                                                                           //upper or lower letter. if any other character present, output error message to user
                        System.out.print("Invalid data in given input. Moving to next word : ");                //and move to next word.
                        break;
                    }
                }
                    word = word.toUpperCase(); 
                    searchWord.patternSearch(readArray, word, counter);
                }
            }
            List.close();
        }
        else
        {
            System.out.print("Enter a word to search for: ");
            Scanner in = new Scanner(System.in);
            String userWord = in.nextLine();                                                                        //get user input and convert string to all uppercase.
            for(int i = 0; i < userWord.length(); i++)
            {
                if(!(Character.isUpperCase(userWord.charAt(i)) || (Character.isLowerCase(userWord.charAt(i)))))     //check to make sure each character in given string to search for is either
                {                                                                                                   //upper or lower letter. if any other character present, output error message to user
                    System.out.print("Invalid data in given input. Moving to next word : ");                        //and move to next word.
                    break;
                }
            }
                userWord = userWord.toUpperCase();
                searchWord.patternSearch(readArray, userWord, counter);
                in.close();
        }
    }
}

class readWordSearch
{
    public static char[][] populateArray(File searchFile) throws FileNotFoundException, IOException
    {   
        char[][]  tempArray = new char[1000][1000];
        char terminator = '`';                                                           //character used to process contents that are read into array.
        String tempS;
        BufferedReader scanSize = new BufferedReader(new FileReader(searchFile));        //buffered reader for line count in file
        Scanner scanner = new Scanner(searchFile);

        for(int i = 0; i <  tempArray.length; i++)
        {
            for(int j = 0; j <  tempArray[0].length; j++)
            {
                tempArray[i][j] = '`';                    //fill array with ` character so that word search is compatible with any size x rows * y columns search. (up to 1000 * 1000)
            }
        }

        scanSize.mark(1);
        tempS = scanSize.readLine();                   //read first line to get column count, then reset cursor in file.
        scanSize.reset();                              //reset cursor to start at beginning of file.
        int rowHold = 0;

        for(int i = 0; i <  tempArray.length; i++)   //loop through temp array and populate it with characters in temporary string that was read from file.
        {
            if((tempS = scanSize.readLine()) != null)
            {                                                   
                if(tempS.matches(".*[a-zA-Z]+.*"))                                  //if read string does not contain a letter, ignore it.
                {
                    int columnHold = 0;
                    for(int j = 0; j < tempS.length(); j++)
                    {
                        if(Character.isUpperCase(tempS.charAt(j)) || (Character.isLowerCase(tempS.charAt(j))))
                        {
                            tempS.toUpperCase();                                      //make string all uppercase. makes it possible to uppercase user input so user can input lower or uppercase values.
                            tempArray[rowHold][columnHold] = tempS.charAt(j);         //populate array with only upper or lowercase letters.
                            columnHold++;
                        }
                    } 
                    rowHold++;
                }
            }
        }

        scanner.close();                                                        //close file i/o
        scanSize.close();
        int rowCount;
        int columnCount;
        for(rowCount = 0; rowCount < tempArray.length; rowCount++)              //get row count. uses ` character to find # of rows.
        {
            if(tempArray[rowCount][0] == terminator)
            {
                break;
            }
        }
        for(columnCount = 0; columnCount < tempArray[0].length; columnCount++)  //get column count. uses ` character to find # of columns.
        {
            if(tempArray[0][columnCount] == terminator)
            {
                break;
            }
        }

        int checkColumn = columnCount;                                          //use first column as 'lookup value'
        for(int i = 0; i < rowCount; i++)                                       //iterate through array and grab smallest column 'length'. 
        {                                                                       //this will be used to populate search array to stay in array index bounds.
            for(int j = 0; j < tempArray[i][columnCount]; j++)
            {
                if((tempArray[i][j] == terminator) && (j <= checkColumn))
                {
                    checkColumn = j;                                            //make checkColumn smallest column 'length'
                    break;
                }
            }
        }

        columnCount = checkColumn;                                              //set column count to check column so that array only gets populated with smallest
        char[][] readArray = new char[rowCount][columnCount];                   //column 'length' as to not exceed array boundaries when searching
        for(int i = 0; i < rowCount; i ++)
        {
            for(int j = 0; j < columnCount; j++)
            {
                readArray[i][j] = tempArray[i][j];
            }
        }
            return readArray;
    }
}

class searchWord
{
    static int R, C, iRow, iCol, fRow, fCol, count;
    // For searching in all 8 directions
    static int[] x = { -1, -1, -1, 0, 0, 1, 1, 1 };  
    static int[] y = { -1, 0, 1, -1, 1, -1, 0, 1 };  
    // This function searches in all 8-direction from point  
    // (row, col) in grid[][]  
    static boolean search2D(char[][] grid, int row, int col, String word)
    {
            count = count + 1;
            // If first character of word doesn't match with  
            // given starting point in grid.  
            if (grid[row][col] != word.charAt(0)) 
            {
                return false; 
            }
            int len = word.length(); 

            // Search word in all 8 directions 
            // starting from (row,col) 
            for (int dir = 0; dir < 8; dir++) 
            { 
                // Initialize starting point 
                // for current direction
                count = count + 1;  
                int k, rd = row + x[dir], cd = col + y[dir];
                iCol = col;                                          //set initial column and row to initial search position.
                iRow = row; 
                // First character is already checked,  
                // match remaining characters 
                for (k = 1; k < len; k++) 
                { 
                    count = count + 1;
                    // If out of bound break 
                    if (rd >= R || rd < 0 || cd >= C || cd < 0) 
                    {
                        break; 
                    }
                    // If not matched, break  
                    if (grid[rd][cd] != word.charAt(k))
                    {
                        break; 
                    }
                    // Moving in particular direction  
                    rd += x[dir]; 
                    cd += y[dir]; 
                } 
                // If all character matched, then value of k must
                // be equal to length of word 
                if (k == len) 
                {
                    fCol = cd;
                    fRow = rd;
                    return true;  
                }
            } 
        return false; 
    } 

    // Searches given word in a given 
    // matrix in all 8 directions 
    static int patternSearch(char[][] grid, String word, int counter) 
    { 
        // Consider every point as starting  
        // point and search given word
        int found = 0;  
        for (int row = 0; row < R; row++)  
        { 
            for (int col = 0; col < C; col++)  
            {
                if (search2D(grid, row, col, word)) 
                {
                    String direction = getDirection(iRow, iCol, fRow, fCol);
                    counter = searchWord.count;
                    System.out.println("pattern found at " + row +  ", " + col + " Facing : " + direction + " : " + word + "(" + counter + ")");
                    searchWord.count = 0;
                }
                else
                {
                    found += 1;                     //counter for times non matching character found
                }
            } 
        } 
        if(found == (R * C))                        //if iterated through whole array and found = size of rows * size of columns                  
        {                                           //(final position in array and still nothing found), output the word and that it was not found
            System.out.println("Word " + word + " not found");
        }
        found = 0;
        return count;
    }
    
    //gets direction based on initial row/column and final row/column
    static String getDirection(int iRow, int iCol, int fRow, int fCol)
    {
        if((iRow > fRow) && (iCol == fCol))
        {
            return "N";
        }
        else if((iRow == fRow) && (iCol < fCol))
        {
            return "E";
        }
        else if((iRow < fRow) && (iCol == fCol))
        {
            return "S";
        }
        else if((iRow == fRow) && (iCol > fCol))
        {
            return "W";
        }
        else if((iRow > fRow) && (iCol > fCol))
        {
            return "NW";
        }
        else if((iRow > fRow) && (iCol < fCol))
        {
            return "NE";
        }
        else if((iRow < fRow) && (iCol < fCol))
        {
            return "SE";
        }
        else if((iRow < fRow) && (iCol > fCol))
        {
            return "SW";
        }
        return "a";
    }
}