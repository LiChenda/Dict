$('#wordinfo').ready(function(){
    $('.done_btn').hide();
    word_en = $('#word_en').text();
    $('.edit_btn').click(function(){
        s = $(this).attr('id');
        num = s[s.length - 1]; 
        $('#edit_'+num).load('/edit?word='+word_en+'&num=' + num);
        $(this).text('cancel');
        $('#done_btn_'+num).show();
        $(this).click(function(){
            $('#searchbtn').click();
        });
    });
    $('.done_btn').click(function(){
        s = $(this).attr('id');
        num = s[s.length - 1]; 
        en = $('#input_en_' + num).val();
        ch = $('#input_ch_' + num).val();
        $.post('/modifysen',{
            'word': word_en,
            'num': num,
            'en': en,
            'ch': ch
        }, function(data, status){
            if(data == 'ture')
            $('#searchbtn').click();
        });

    });
})

