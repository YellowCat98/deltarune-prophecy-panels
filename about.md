# Deltarune Prophecy panels

- A mod that adds the prophecy panels from Deltarune Chapter 4.
- Has a chance of showing a prophecy panel of your choice every time you switch to a new menu in-game.

## How prophecy sprites work
- The `Prophecy Sprite` setting in this mod's settings dictates what sprite to use for the prophecy.
- This mod just uses the sprite as a mask for the prophecy light-blue effect. Meaning all opaque pixels are processed the same. Only transparent pixels are ignored.
- Below is a comparison between how it looks like outside the game VS how it looks like in-game.

![Comparison](yellowcat98.deltarune_panels/comparison_about.png?scale=2.0)

- (The sprite looks bigger in-game because the mod scales it up)
- Switching the texture quality will change the texture too because UHD sprites are bigger than HD and Low sprites. Make the sprite's size depending on your texture quality.




## How text works
- The `Prophecy Text` setting in this mod's settings dictates the text to use in the prophecy text.
- It works the way you'd expect it to work. Just put in text.
- The special quirk is that it doesn't support lowercase characters, meaning "Papyrus is the roaring knight." turns into "PAPYRUS IS THE ROARING KNIGHT.". Also the # character gets turned into a new-line. putting # makes the text after its own separate line.


- NOTE: If you change the `Prophecy Sprite` or `Prophecy Text` in this mod's settings, or change your resolution, you will have to press the `Reload Prophecy` button to refresh it.

## Credits
- Couldn't be done without finding this [forum](https://www.spriters-resource.com/pc_computer/deltarune/asset/275345/) online.
- Prophecy font taken from [here](https://www.reddit.com/r/Deltarune/comments/1lc76wu/made_the_prophecy_font_into_a_downloadable_ttf/)
- Used [DeltaProphecy](https://deltaprophecy.vercel.app/) for reference, this mod aims to achieve the same look as DeltaProphecy. (except the text, we don't talk about that.)
- Deltarune Prophecy effect assets made by Toby Fox.