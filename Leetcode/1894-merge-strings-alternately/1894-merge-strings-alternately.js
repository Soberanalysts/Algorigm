/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    const lens=word1.length + word2.length;
    output=[];
    let index;
    for(let i=0; i<word1.length; i++) {
        output[i*2]=word1[i];
    }
    for(let i=0; i<word2.length; i++) {
        output[i*2+1]=word2[i];
        // index=Math.floor(i/2)
        // if(i%2==0 && i < word1.length) {
        //     output+=word1[index];
        // } else if(i%2==1 && i < word2.length){
        //     output+=word2[index];
        // }
    }
  
    return output.join("");
};