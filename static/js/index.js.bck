



$('#inputword .typeahead').typeahead({
    hint: true,
    highlight: true,
    minLength: 1,
},
{
    async: true,
    name: 'states',
    source: function(query, processSync, processAsync){
        processSync([]);
        return $.ajax({
            url: "/typeahead",
            type: 'GET',
            data: {query: query},
            dataType: 'json',
            success: function(json){
                return processAsync(json);
            }
        });
    }
});
