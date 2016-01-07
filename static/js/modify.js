$('#wordinfo').ready(function(){
    $('.done_btn').hide();
    word_en = $('#word_en').text();

    $('.del_btn').click(function(){
        s = $(this).attr('id');
        num = s[s.length - 1]; 
        //del ajax here
        $.post('/delsen', {
            'word': word_en,
            'num': num
        }, function(data, status){
            if(data == 'ture')
                $('#wordinfo').load('/search?word=' + encodeURI($('#inputed').val()));

        });

    });
    $('.edit_btn').click(function(){
        s = $(this).attr('id');
        num = s[s.length - 1]; 
        $('#edit_'+num).load('/edit?word='+encodeURI(word_en)+'&num=' + num);
        $(this).text('cancel');
        $('#done_btn_'+num).show();
        $('#del_btn_'+num).hide();
        $(this).click(function(){
            $('#wordinfo').load('/search?word=' + encodeURI($('#inputed').val()));
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
                $('#wordinfo').load('/search?word=' + encodeURI($('#inputed').val()));
        });
    });
    $('#done_btn').hide();
    $('#add_btn').click(function(){
        $(this).text('cancel');
        $('#add_new').load('/addsen_t');
        $('#done_btn').show();
        $(this).click(function(){
            $('#wordinfo').load('/search?word=' + encodeURI($('#inputed').val()));
        });
    });
    $('#done_btn').click(function(){
        en = $('#input_add_en').val();  
        ch = $('#input_add_ch').val();  
        $.post('/addsen',{
            'word': word_en,
            'en': en,
            'ch': ch
        }, function(data, status){
            if(data == 'ture')
                $('#wordinfo').load('/search?word=' + encodeURI($('#inputed').val()));
        });
    });

})

