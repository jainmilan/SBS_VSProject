
function [ tuples ] = toTuples( indices, getColumns )
    if getColumns
        tuples = javaArray('com.ampl.Tuple', size(indices,2));
    else
        tuples = javaArray('com.ampl.Tuple', size(indices,1));
    end
    if(getColumns)
        for i=1:size(indices,2)
            a = indices(:,i);
            a = a{1};
            if(isa(a, 'Tuple'))
                tuples(i) = a.impl;
            else
                tuples(i)=com.ampl.Tuple.join(a);
            end
        end
    else
        for i=1:size(indices,1)
            if(isa(indices(i,:), 'Tuple'))
                tuples(i) = indices(i,:).impl;
            else
                tuples(i)=com.ampl.Tuple.join(indices(i,:));
            end
        end
    end
end

