class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        const int N = 128;
        int ransomNoteDict[N], magazineDict[N];
        
        for (int i = 0; i < N; i++) ransomNoteDict[i] = magazineDict[i] =  0;
        
        for (int i = 0; i < ransomNote.length(); i++) ransomNoteDict[(int) ransomNote[i]]++;
        for (int i = 0; i < magazine.length(); i++) magazineDict[(int) magazine[i]]++;
        
        int canBe = true;
        for (int i = 0; i < N; i++) 
            if (ransomNoteDict[i] > magazineDict[i]) 
                canBe = false;
        return canBe;
    }
};