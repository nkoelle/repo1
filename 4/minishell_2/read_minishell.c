
typedef char** t_input_stream;

char input_stream_peek(t_input_stream stream)
{
    return (*stream);
}

bool    input_stream_has_next(t_input_stream stream)
{
    return (input_stream_peek(stream) != '\0');
}

void    input_stream_advance(t_input_stream stream)
{
    (*stream)++;
}

void    read_single_quoted(char **ptr, t_stringbuffer *buffer)
{
    while (**ptr != '\'')
    {
        stringbuffer_append_char(buffer, **ptr);
        (*ptr)++;
    }
}

char *read_identifier(char **ptr)
{
    t_stringbuffer  buffer;
    char            *str;

    stringbuffer_create(&buffer);
    
    while (1)
    {
        if (**ptr == '\'')
            read_single_quoted(ptr, &buffer);
        else if (**ptr == '"')
            read_double_quoted(ptr, &buffer);
        else if (**ptr == '$')
        {
            char *value = get_value(read_varname(ptr)); 
            stringbuffer_append_string(&buffer, value);
        }
        else if (is_breaking_char(**ptr))
        {
            break ;
        }
        else
        {
            stringbuffer_append_char(&buffer, **ptr);
            input_stream_advance(stream);
            (*ptr)++;
        }
    }

    stringbuffer_get_string(&buffer, &str);
    stringbuffer_destroy(&buffer);
    return (str);
}

void parse(char **ptr)
{
    char *ident;
    <skip_whitespace(ptr);>
    
    if (check(ptr, "<<"))
    {
        skip_whitespace(ptr);
        append_string_to_redirection_list(&redirection_list, HEREDOC, read_identifier(ptr));
    }
    else if (check(ptr, ">>"))
    {
        skip_whitespace(ptr);
        append_string_to_redirection_list(&redirection_list, OUT_APPEND, read_identifier(ptr));
    }
    if (check(ptr, "<"))

    else if (check(ptr, "|"))
    {
        clearen und die listen vor | und füge sie 
    }
    else
    {
        append_string_to_linked_list(&argv_list, read_identifier(ptr));
    }
}
