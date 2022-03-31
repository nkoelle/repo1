> $USER // bei Doc wenn quotes in der ausführung sind kann nicht $USER geprintet werden
> end
$USER
bash-3.2$ cat <<ned
> $USER
> ned
nmichael
bash-3.2$ cat <<'ned'


// typedef char** t_input_stream;

// char input_stream_peek(t_input_stream stream)
// {
//     return (*stream);
// }

// bool    input_stream_has_next(t_input_stream stream)
// {
//     return (input_stream_peek(stream) != '\0');
// }

// void    input_stream_advance(t_input_stream stream)
// {
//     (*stream)++;
// }

//to-do = redirection list erstellen, argv_list erstellen
//wir haben einen doppel pointer um am ende einfach den ersten zu freen
void parse(char **ptr) //mit einem doppel pointer verändert man nicht den orginal pointer, kommt man in eine subfunktion kann man
{
    char *ident;
    if (ptr == ' ' || ptr == '\t')
        ptr++;
    if (check(ptr, "<<"))
    {
        while(ptr == ' ' || ptr == '\t')
            ptr++;
        append_string_to_redirection_list(&redirection_list, HEREDOC, read_identifier(ptr));
    }
    else if (check(ptr, ">>"))
    {
        while(ptr == ' ' || ptr == '\t')
            ptr++;
        append_string_to_redirection_list(&redirection_list, OUT_APPEND, read_identifier(ptr)); //redirection list erstellen
    }
    else if (check(ptr, "< "))
        while(ptr == ' ' || ptr == '\t')
            ptr++;
    else if (check(ptr, ">"))
        while(ptr == ' ' || ptr == '\t')
            ptr++;
    // else if (check(ptr, "|"))
    // {
    //     liste neu initialisieren und das ergebnis vor der pipe übergeben. --nochmal später anschauen 
    // }
    else
    {
        append_string_to_linked_list(&argv_list, read_identifier(ptr));
    }
}


<< END < /home/infile grep -v 42 | ">> outfile1 wc -l > outfile2" | ls | > outfile3 | echo don't | split << Makefile

">>








{
    t_stringbuffer  buffer;
    char            *str;

    stringbuffer_create(&buffer);
    stringbuffer_append_itoa(&buffer, 42);
    stringbuffer_create_node(&buffer, &str);
    stringbuffer_destroy(&buffer);
    return (str);
}


void    stringbuffer_append_str(t_stringbuffer* buffer, char *str)
{
    while (*str != '\0')
    {
        stringbuffer_append_char(buffer, *str);
        str++;
    }
}

void    stringbuffer_append_itoa(t_stringbuffer* buffer, int value)
{
    // ...
    stringbuffer_append_char(buffer, "0123456789"[value % 10]);
}

char    *itoa(int value)
{
    t_stringbuffer  buffer;
    char            *result;

    stringbuffer_create(&buffer);
    stringbuffer_append_itoa(&buffer, value);
    stringbuffer_create_node(&buffer, &result);
    stringbuffer_destroy(&buffer);
    return (result);
}


t_reader    reader;

reader_create_from_file(&reader, "/tmp/test.txt");
reader_create_from_str(&reader, "asjoidjasiodj asidjasoi djasoijdiasj dasd");

while (reader_has_next_char(&reader))
{
    stringbuffer_append_char(&buffer, reader_peek(&reader));
    if (reader_peek(&reader) == '\n')
        break ;
    reader_advance(&reader);
}
