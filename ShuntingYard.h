#ifndef SHUNTINGYARD_H
#define	SHUNTINGYARD_H

class ShuntingYard {
    public:
        vector<string> tokenize(string equation);
        void analyze(vector<string> tokenVector);
        int precedence(string token);
        bool leftAsso(string token);
    private:
        vector<string> tokens;
        
};

#endif	/* SHUNTINGYARD_H */

