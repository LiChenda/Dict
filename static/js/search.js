$(document).ready(function(){
    $("#searchbtn").click(function(){
          $('#wordinfo').load('/search/' + $('#inputed').val());
    });
    $("#inputed").bind('keypress', function(event){
        if(event.keyCode == 13)
        {
          $('#wordinfo').load('/search/' + $('#inputed').val());

        }
    });
});
