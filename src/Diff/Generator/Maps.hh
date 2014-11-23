<?hh // strict

namespace Diff\Generator;

class Maps<Tk, Tv> implements Generator
{
    public function __construct(private Map<Tk, Tv> $from, private Map<Tk, Tv> $to) {}

    public function diff(): string
    {
        $output = "";
        $usedKeys = Vector{};
        foreach ($this->from as $key => $value) {
            if ($this->to->contains($key) && $this->to[$key] == $value) {
                $output .= " {$key} => {$value}\n";
                $usedKeys[] = $key;
            } else {
                $output .= "-{$key} => $value\n";
            }
        }

        foreach ($this->to as $key => $value) {
           if ($usedKeys->linearSearch($key) === -1) {
                $output .= "+{$key} => $value\n";
           }
        }

        return $output;
    }
}
