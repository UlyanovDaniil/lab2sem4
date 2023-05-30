#include <iostream>
#include <fstream>
#include "ForwardList.h"
#include "MyString.h"

int main()
{
  std::ifstream fin;
  TForwardList<TForwardList<TString>> text = TForwardList<TForwardList<TString>>();
  int post = 0, posp = 0, posw = 0, numt = 0, nump = 0, numw = 0;
  bool runt = true, runp = true, runw = true;

  setlocale(LC_ALL,"ru");

  while (runt)
  {
    TForwardList<TString> paragraph = TForwardList<TString>();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout <<
      "1. �������� ����� � ������\n" <<
      "2. �������� ����� � �����\n" <<
      "3. �������� ����� �� ����� n\n" <<
      "4. ������� ����� �� ������\n" <<
      "5. ������� ����� �� ������\n" <<
      "6. ������� ����� �� �����\n" <<
      "7. ������� �����\n" <<
      "8. �����\n";

    std::cin >> post;

    switch (post)
    {
    case 1:
      text.AddBegin(paragraph);
      break;
    case 2:
      text.AddEnd(paragraph);
      break;
    case 3:
      std::cout << "������� ����� ������:";

      std::cin >> numt;

      text.Add(paragraph, numt);
      break;
    case 4:
      std::cout << "������� ����� ������:";
      
      std::cin >> numt;

      while (runp)
      {
        TString str = TString();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout <<
          "1. �������� ����� � ������\n" <<
          "2. �������� ����� � �����\n" <<
          "3. �������� ����� �� ����� n\n" <<
          "4. ������� ����� �� ������\n" <<
          "5. ������� ����� �� ������\n" <<
          "6. ������� �����\n" <<
          "7. �����\n";

        std::cin >> posp;

        switch (posp)
        {
        case 1:

          std::cout << "������� �����:";

          std::cin >> str;

          text[numt].AddBegin(str);

          break;
        case 2:
          std::cout << "������� �����:";

          std::cin >> str;

          text[numt].AddEnd(str);

          break;
        case 3:
          std::cout << "������� ����� �����:";

          std::cin >> nump;
          
          std::cout << "������� �����:";

          std::cin >> str;

          text[numt].Add(str, nump);

          break;
        case 4:
          std::cout << "������� ����� �����:";

          std::cin >> numw;

          while (runw)
          {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout <<
              "1. �������� �����\n" <<
              "2. ������� �����\n" <<
              "3. �����\n";

            std::cin >> posw;

            switch (posw)
            {
            case 1:
              std::cout << "������� �����:";

              std::cin >> text[numt][numw];

              break;
            case 2:
              std::cout << text[numt][numw] << "\n";

              break;
            case 3:
              runw = false;

              break;
            default:
              break;
            }
          }

          runw = true;

          break;
        case 5:
          std::cout << "������� ����� �����:";

          std::cin >> numw;

          text[numt].Delete(numw);

          break;
        case 6:
          std::cout << text[numt] << "\n";

          break;
        case 7:
          runp = false;

          break;
        default:
          break;
        }
      }

      runp = true;

      break;
    case 5:
      std::cout << "������� ����� ������:";

      std::cin >> numt;

      text.Delete(numt);

      break;
    case 6:
      fin.open("../../text.txt");

      text.Clear();
      text.AddBegin(paragraph);
      text[0].AddBegin("");

      if (fin.is_open())
      {
        char c;
        int countp = 0, countw = 0;

        while (fin.get(c))
        {
          TString str = TString(1, c);

          if (c == ' ')
          {
            countw++;
            text[countp].AddEnd("");
          }
          else if (c == '\n')
          {
            countp++;
            text.AddEnd(paragraph);
            text[countp].AddEnd("");
            countw = 0;
          }
          else
          {
            text[countp][countw] += str;
          }
        }
      }
      else
      {
        std::cout << "������ �������� �����\n";
      }

      break;
    case 7:
      for (int i = 0; i < text.GetCount(); i++)
      {
        std::cout << text[i] << "\n";
      }

      break;
    case 8:
      runt = false;

      break;
    default:
      break;
    }
  }

  fin.close();

  return 0;
}