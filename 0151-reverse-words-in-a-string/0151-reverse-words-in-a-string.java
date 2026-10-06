class Solution {
    public String reverseWords(String s) {
        
        int i = s.length() - 1;

        String result = "";

        while(i >= 0){

            while(i >= 0 && s.charAt(i) == ' '){
                i--;
            }

            if(i < 0) break;

            int end = i;

            while(i >=0 && s.charAt(i) != ' '){
                i--;
            }

            String str = s.substring(i+1,end+1);

            if(!result.isEmpty()) result += ' ';

            result += str;


        }

        return result;



    }
}