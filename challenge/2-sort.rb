result = []

ARGV.each do |arg|
  next unless arg =~ /^-?\d+$/

  i_arg = arg.to_i
  is_inserted = false
  i = 0
  l = result.length

  while !is_inserted && i < l
    if result[i] <= i_arg
      i += 1
    else
      result.insert(i, i_arg)
      is_inserted = true
    end
  end

  result << i_arg unless is_inserted
end

puts result
