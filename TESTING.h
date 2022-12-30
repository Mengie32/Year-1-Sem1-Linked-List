// only exists for debugging and testing

#pragma once
int operator(int (*func)(int), int input);

int Double(int i);

//creates random records
void createRandom(record** listHead, int length, int count);