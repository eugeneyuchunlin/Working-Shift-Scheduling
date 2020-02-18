$('#test').click(function (e) { 
    e.preventDefault();
    console.log('button click')
    $('#text').append("Please wait");
    // $.ajax({
    //     type: "GET",
    //     url: "test/",
    //     success: function (response) {
    //         console.log(response)
    //         $('#text').empty();
    //         $('#text').append("Successful")
    //     }
    // });
});
