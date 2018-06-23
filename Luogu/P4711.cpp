// FBI WARNING: 这道题算五水硫酸铜是错的
#include <iostream>
#include <cmath>
#include <string>
#include <map>
using namespace std;

map<string, float> elements;
void init() { // 初始化，给每个元素定义质量
	elements["H"] = 1;
	elements["C"] = 12;
	elements["N"] = 14;
	elements["O"] = 16;
	elements["F"] = 19;
	elements["Na"] = 23;
	elements["Mg"] = 24;
	elements["Al"] = 27;
	elements["Si"] = 28;
	elements["P"] = 31;
	elements["S"] = 32;
	elements["Cl"] = 35.5;
	elements["K"] = 39;
	elements["Ca"] = 40;
	elements["Mn"] = 55;
	elements["Fe"] = 56;
	elements["Cu"] = 64;
	elements["Zn"] = 65;
	elements["Ag"] = 108;
	elements["I"] = 127;
	elements["Ba"] = 137;
	elements["Hf"] = 178.5;
	elements["Pt"] = 195;
	elements["Au"] = 197;
	elements["Hg"] = 201;
  /*
  elements.insert(pair<string, float>("H",1));
  elements.insert(pair<string, float>("C",12));
  elements.insert(pair<string, float>("N",14));
  elements.insert(pair<string, float>("O",16));
  elements.insert(pair<string, float>("Na",23));
  elements.insert(pair<string, float>("Mg",24));
  elements.insert(pair<string, float>("Al",27));
  elements.insert(pair<string, float>("Si",28));
  elements.insert(pair<string, float>("P",31));
  elements.insert(pair<string, float>("S",32));
  elements.insert(pair<string, float>("Cl",35.5));
  elements.insert(pair<string, float>("K",39));
  elements.insert(pair<string, float>("Ca",40));
  elements.insert(pair<string, float>("Mn",55));
  elements.insert(pair<string, float>("Fe",56));
  elements.insert(pair<string, float>("Cu",64));
  elements.insert(pair<string, float>("Zn",65));
  elements.insert(pair<string, float>("Ag",108));
  elements.insert(pair<string, float>("I",127));
  elements.insert(pair<string, float>("Ba",137));
  elements.insert(pair<string, float>("Hf",178.5));
  elements.insert(pair<string, float>("Pt",195));
  elements.insert(pair<string, float>("Au",197));
  elements.insert(pair<string, float>("Hg",201));
  */
}

string input; // 定义输入字符串

bool checkAlphaValid(char& check) { // 确认参数是一个元素字母而不是符号
  if(isalpha(check)) return true; else return false;
  // if(check != '(' && check != ')' && check != '_' && check != '{' && check != '}' && (check < '0' || check > '9') ) return true; else return false;
}

int pointer = 0; // 字符串的“指针”
float massTotal = 0; // 总质量（所有元素）
float mass; // 定义单个质量
void readElements() { // 函数执行一次只读取一个元素的质量
  string element; // 定义单个元素
  if(checkAlphaValid(input[pointer])) { // 确认现在指针所指的是一个元素字母而不是符号
    element += input[pointer]; // 读入第一个字母给元素字符串。如Hg的H
    pointer++; // 指针向右移一位，读取输入的下一位
    if(elements.count(element)) { // 如果第一个字母以元素的形式成立（可以被检索到）。如Hg在此处只检索H；但Au在这里的A明显无法检索，所以Ag和Au在此处都是直接跳else
      mass = elements[element]; // 获取第一个字母以元素的形式的质量，如H的质量为1便直接赋给这次函数的质量
      if(checkAlphaValid(input[pointer])) { // 现在向右移一位指针，即可以读取Hg的g
        element += input[pointer]; // 读入第二个字母给元素字符串
        pointer++; // 指针向右移一位，读取输入的下一位
        if(elements.count(element)) { // 如果第二个字母以元素的形式成立（可以被检索到）。如KMnO4在此处会因为没有KM这个元素而停止检索
          mass = elements[element]; // 覆盖修正前面读取不完全时获取到的错误质量，如用Hg的质量来覆盖H的质量
        } else {
          pointer--; // 此次读入是失败的，退回无效字符留给下次读入
        }
      }
    } else {
      element += input[pointer]; // 如果第一个字母不成元素（不可以被检索到）。如Ag和Au只能检索到A在此处加以补全
      pointer++; // 指针向右移一位，读取输入的下一位（为下一次函数运行的读取作准备，此次函数运行不再读取）
      mass = elements[element]; // 获取这个2个字母长的元素的质量
    }
  } else {
    pointer++;
  }
  massTotal += mass; // 将此次函数运行获得的单个元素质量算入总质量
}

bool checkNumberValid(char& check) {
  if(isdigit(check)) return true; else return false;
}

void readQuantity() {
  int quantity = 0; // 定义数量
  string quanStr; // 定义数量所对的子字符串（较输入字符串）
  while(input[pointer] != '}') {
    quanStr += input[pointer]; // 把数字全部读入子串
    pointer++; // 指针向右移一位，读取输入的下一位
  }
  pointer++; // 跳过}这个无用的字符
  for(int i = 0; i < (int)quanStr.length(); i++) {
    quantity += (quanStr[i] - '0') * pow(10, quanStr.length() - i - 1); // 一位一位数转换
  }
  massTotal += mass * (quantity - 1); // 前面算单个质量时已经加过一次，所以此处将数量减1
}

void readGroup() {
  int massTotalOld = massTotal;
  while(input[pointer] != ')') {
    if(input[pointer] == '_') {
      pointer += 2; // 跳过_{这两个无用的字符
      readQuantity(); // 读取数量
      continue; // 处理完毕此次分质量，获取下一个元素
    }
    readElements(); // 获得单个元素的质量
  }
  mass = massTotal - massTotalOld; // 求出质量差
  massTotal -= mass; // 不知道为什么要加这行
}

void readWater() {
  int quantity = 0; // 定义数量
  string quanStr; // 定义数量所对的子字符串（较输入字符串）
  if(input[pointer] == 'H') {
    quantity = 1;
  }
  while(input[pointer] != 'H') { // 读完H_{2}O前面的所有数字
    quanStr += input[pointer]; // 把数字全部读入子串
    pointer++; // 指针向右移一位，读取输入的下一位
  }
  for(int i = 0; i < (int)quanStr.length(); i++) {
    quantity += (quanStr[i] - '0') * pow(10, quanStr.length() - i - 1); // 一位一位数转换
  }
  massTotal += 18 * quantity; // 前面算单个质量时已经加过一次，所以此处将数量减1
}

int main() {
  ios::sync_with_stdio(false);
  init(); // 初始化，给每个元素定义质量
  cin >> input; // 输入化学式
  while(pointer < input.length()) { // 一直读入，直到将输入的化学式读完，获得每个元素的质量
    if(input[pointer] == '_') {
      pointer += 2; // 跳过_{这两个无用的字符
      readQuantity(); // 读取数量
      continue; // 处理完毕此次分质量，获取下一个元素
    }
    if(input[pointer] == '(') {
      pointer++;
      readGroup();
      continue;
    }
    if(input[pointer] == '~') {
      pointer++;
      readWater();
      break;
    }
    readElements(); // 获得单个元素的质量
  }
  cout << massTotal << endl; // 输出总质量
  return 0;
}
