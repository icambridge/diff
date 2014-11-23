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
                $output .= " " . (string) $key . " => " . (string) $value . "\n";
                $usedKeys[] = $key;
            } else {
                $output .=  "-" . (string) $key . " => " . (string) $value . "\n";;
            }
        }

        foreach ($this->to as $key => $value) {
           if ($usedKeys->linearSearch($key) === -1) {
                $output .=  "+" . (string) $key . " => " . (string) $value . "\n";
           }
        }

        return $output;
    }
}
